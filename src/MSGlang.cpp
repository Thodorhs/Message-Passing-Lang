#include <iostream>
#include <vector>
#include <string>

#ifndef _MSGlang_H
#include "MSGlang.h"
#endif

ostream& operator <<(ostream& out, obj& x){
    out << "object [";
    for (size_t i = 0; i != x.package.size(); ++i){
        switch(x.type[i]){
        case 0:
            out << "\""<< x.package[i] <<"\":" << x.value[i].i;
            break;
        case 1:
            out << "\""<< x.package[i] <<"\":" << x.value[i].s;
            break;
        case 2:
            out << "\""<< x.package[i] <<"\":" << x.value[i].d;
            break;
        case 3:
            out << "\""<< x.package[i] <<"\":" << x.value[i].b;
            break;
        case 4:
            //out << "\""<< x.package[i] <<"\":" << x.value[i].f;
            break;
        case 5:
            obj* k=x.value[i].o;
            cout<<&k;
            break;               
        }
        if(i+1!= x.package.size()){
            out<<",";
        }
    }
    out<<"]";
    return out;
}