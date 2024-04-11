
# Construction of a Language for Message Passing.

The subject of the project is the construction of a domain-specific language for defining objects that receive messages for execution from other objects. A message to an object is a "request" for the execution of a process by it.

*CS-352 Computer Science Department University of Crete*

## Prerequisites
- g++
- make

## Run
You can use the src/main.cpp to write Message Passing language inside the main() function like shown bellow.

## Structure - Implementation
To achieve this functionality, we create a set of preprocessor macros for keywords, operator overloading and template containers offered by the STL to store the different objects of the program that provide specific functionality (described below) and determine the structure of the language.

The language we construct will be compiled to C++, so we need one header file with appropriate definitions to ensure that the program, written in the domain-specific language, corresponds to valid C++ code and compiles correctly. Similar to C++, whitespaces are ignored.

A program will always have the following format:
```
#include <MSGlang.h>
int main() {
    // Definitions can be in any order, but before passing the message
    object definition
    message definition
    pass message to object
}
```

## Definition of Object variable

Objects can be declared as variables in the language by following the syntax:
```
let name1 = object;
let name2 = object[ values val1, val2, val3... ];
let name3 = object[
 key(id1) = val1,
 key(id2) = val2,
 key(id3)= lambda{body1},
 func(id4){body2} ...
];
```
- The name is the variable name of the object and follows all the variable naming rules of C++.
- The let keyword represents any type supported by C++, as well as user-defined types, and is always followed by an initializer.
- The key keyword is used to declare a variable within the object that we access through the id passed in parentheses.
- The vali is the value of each field of the object, which can take the following values:
  ```
  int bool string double (c++ types)
  object
  function (object functions)
  ```
- The idi is a string.
- The values keyword groups each argument to the right of it, separated by commas, into an array of values. These values are accessible by indexing as in an array, with the difference that they are strings (i.e., indexed with "0", "1", etc., and not 0, 1, etc., as in C++).
- Objects are printable in the following format. (Note! Fields that are of function type are printed as methods)

  ```object [ “id1”:value1, … , “idn”: method ]; ```
- An object can have as many fields as desired.
- The none keyword corresponds to an empty value. For example, return none; returns an empty variable.

## Access and Modification of Object Fields

Objects should be accessible from any point in the program. We can access their fields using their id and change their value, as shown below:
```
obj_name[id] = value; // The id must be a string
o1["x"]; // Returns the field with id "x" from the object named o1 (i.e., -1)
o1["x"] = 0; // Changes the value of the field "x" to 0
o3["2"] = false; // Changes the value of the field "2" to false in the object o3
```
- input: The input function is used with the syntax input(msg), where msg is a string. It is a function that prints msg to the console, waits for input from the user, and once it is read, returns it. The input that will be read can be of type double, int, bool, or string. For example:
  ```
  o1["x"] = input("x:"); // This will print the message "x:" to the console and wait for input from the user, returning it. Then, the input is stored in the field "x" of object o1.
  ```
- ref: It takes as an argument the name of an object variable and gives us a reference to the entire object, allowing us to refer to an existing object instead of copying it. For example, ref(o3) will return a reference to the object o3.

## Functions of Language Objects

The language supports the declaration of functions as fields within objects. Functions should return a value and take no parameters. In cases where no return value is desired, the keyword "none" should be returned.

Functions can be created using two methods: the keywords lambda and func.

- The func keyword is used to declare a function followed by its id and body, and it is a member of an object.
  ```
  func(id){body}
  ```
- The lambda keyword is immediately followed by the body of the function, and it must be stored in a key to be a member of an object.
  ```
  lambda {body}
  ```
The syntax key(id) = lambda{body} is equivalent to func(id){body}.

**-Reference to object fields within a function.-**

Within the body of a function, we can refer to the members of an object using the keywords self and arg. Note that the function will be executed by the receiver.

- The self keyword returns the variable with the id specified in parentheses, which is located in the receiving object that will execute the function.
  ```
  self(x) // returns the member with id = "x" located in the receiving object
  ```
- The arg keyword returns the variable with the id specified in parentheses, which is located in the sender object that will send the message.
  ```
  arg(y) // returns the member with id = "y" located in the message object
  ```

## Message Passing

The transfer of a message from one object to a receiving object should be done using the following method, using the << operator:

```
rec_object << msg_object; // The msg_object sends a message to the rec_object
```

- The rec_object is the name of the object that will receive the message, and the msg_object will be the object that provides the arguments to the rec_object to execute the message.
- To create a receiving object, we follow the same syntax as the objects seen above, but there must be a function within the object that will serve the message request.
- The msg_object must have an additional parameter call(id). You need to define the call keyword so that when message passing occurs, the function with the id within the parentheses is called on the receiver.

Below is the declaration of a receiving object whose "printf" function, when called, will print the parameters we pass. The nl keyword represents the new line character.

```
let printf_impl = object [
 func("printf") {
 for (auto& v : args_list)
 std::cout << v << nl;
 return none;
 }
];
```
By adding the field call("printf") to the following message object, the message is ready to be sent to the printf_impl object.

```
o3 = object [ call("printf"), values 1, "2", true, -3.14 ];
printf_impl << o3; // The printf function is called on the receiver and prints one by one the arguments of o3, printing 1, "2", true, -3.14
```

## Executing Message Functions
To add the ability for receiving objects to execute the functions we send as messages and easily iterate through the parameters of the message, we define the following keywords:

- args_list: Returns an iterable list with all the arguments received by the receiver.
- eval: Takes as an argument the id of a function passed as an argument and executes it. For example:
  ```
  eval("mid"); // Executes (if exists) the function with id "mid" from the sending object.
  ```
- eval_cond: Takes as an argument the id of a function passed as a logical condition and returns the Boolean evaluation of the function. (See below for example usage of the keywords.)
