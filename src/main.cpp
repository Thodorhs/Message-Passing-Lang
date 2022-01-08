#include <iostream>
using namespace std;

#ifndef _MSGlang_H
#include "MSGlang.h"
#endif


int main(){
    let name1 = object[values 3,key("k") = -4,string("ege"),key("k") = -4,key("l") = -2];
    let name2 = object[values 3,string("alexm"), true, 5, 3.2 ,name1 ];

    cout<<name1<<endl;
    cout<<name2<<endl;

    let o1 = object [key("x") = -1,key("y") = -2,key("k") = -4,key("l") = -2];

    let o2 = object; // άδειο object
    let o3 = object [ values 1, "2", true, -3.14 ]; 

    cout << o1;

    /*let name3 = object[ 
    key(id1) = val1,
    key(id2) = val2, 
    key(id3)= lambda{body1}, 
    func(id4){body2} ...
    ];*/
    return 0;
}