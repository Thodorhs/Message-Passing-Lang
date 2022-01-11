#include <iostream>
using namespace std;

#ifndef _MSGlang_H
#include "MSGlang.h"
#endif


int main(){
    let name1 = object[values 3,key("k") = -4,"ege",key("l") = "this a string giorghs is gay"];
    let name2 = object[values 3,"alexm", 5, 3.2 ,name1];

    cout<<name2<<endl;

    name1["k"] = -37;
    cout<<name1<<endl;
    name1["l"] = "niko is gay";
    cout<<name1<<endl;

    name1["k"] = input("k:");
    cout<<name1<<endl;

    let o1 = object [key("x") = -1,key("y") = -2,key("k") = -4,key("l") = -2, func("s"){cout<<"good job"<<endl;return true;} ];
    let o2 = object; // άδειο object
    let o3 = object [ values 1, "2", true, -3.14 ]; 
    cout<<o1;
    return 0;
}