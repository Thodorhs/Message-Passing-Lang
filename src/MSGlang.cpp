#include <iostream>
#include <vector>
#include <string>

#ifndef _MSGlang_H
#include "MSGlang.h"
#endif

void print_obj(obj x){
    int c=0;
    cout << "object [";
    for (auto i = x.package.begin(); i != x.package.end(); ++i){
        string s("");
        s=s+to_string(c);    
        cout << "\""<< s <<"\":"<<*i<<",";
        c++;
    }
    cout<<"];"<<endl;
}