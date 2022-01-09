#include <iostream>
using namespace std;

#ifndef _MSGlang_H
#include "MSGlang.h"
#endif


int main(){
    let name1 = object[values 3,key("k") = -4,"ege",key("f") = true,key("l") = "this a string giorghs is gay"];
    let name2 = object[values 3,"alexm", true, 5, 3.2 ,name1];

    cout<<name2<<endl;

    name1["k"] = -37;
    cout<<name1<<endl;
    name1["l"] = "niko is gay";
    cout<<name1<<endl;

    name1["k"] = input("k:");
    cout<<name1<<endl;


    let o1 = object [key("x") = -1,key("y") = -2,key("k") = -4,key("l") = -2,  key("f") = lambda{int a=3;cout<<"good job"<<endl;return 0;}  ];
    let o2 = object; // άδειο object
    let o3 = object [ values 1, "2", true, -3.14 ]; 
    cout<<o1;
     let connection = object[
        call("connect"),
        key("ip") = "1.1.1.1",
        key("bool") = true,
        key("port") = 5000,
        func("cond"){ return arg(port) == self(port);},
        func("success"){
            cout << arg(ip) << " connected to " 
            << self(ip) << nl;
            return true;
        },
        func("failure"){
            cout << arg(ip) << " failed to connect to" 
            << self(ip) << nl;
            return false;
        }
    ];
    cout<<connection;
    let conn_impl = object[
        key("ip") = "127.0.0.1",
        key("port") = 3030,
        func("connect"){
            //x.value[i]
            if(eval_cond("cond")){
                eval("success");
            }
            else
                eval("failure");
            return false;
        }
    ];

    conn_impl << connection;
    return 0;
}