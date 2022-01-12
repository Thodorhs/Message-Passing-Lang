#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <string.h>

#ifndef _MSGlang_H
#include "MSGlang.h"
#endif

obj::obj(){
    this->is_key=0;
}
obj::obj(const char * s){
    this->package.push_back(string(s));
    this->is_key=1;
    change_id=s;
}
obj::obj(string s){
    this->func_to_call=s;
}
ostream& operator <<(ostream& out, obj& x){
    ostringstream ss;
    obj *k;
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
            ss << boolalpha << x.value[i].b;
            out << "\""<< x.package[i] <<"\":" << ss.str();
            break;
        case 4:
            out << "\""<< x.package[i] <<"\":" << string("method");
            break;  
        case 5:
            k=x.value[i].o;
            cout<<*k;
            break;                                   
        }
        if(i+1!= x.package.size()){
            out<<",";
        }
    }
    out<<"]";
    return out;
}
struct val input(const char *s){
    struct val strv;
    string in=string();
    cout << s;
    cin >> in;
    try {
        int i = stoi(in);
        strv.i = i;
        return strv;
    }catch(...){
        try{
            cout << "im here"<<endl;
            double d=stod(in);
            strv.d = d;
            return strv;
        }catch(...){
            if(strcmp(in.c_str(),"true")==0){
                strv.b=true;
                return strv;
            }else if(strcmp(in.c_str(),"false")==0){
                strv.b=false;
                return strv;
            }  
        strv.s=in;
        return strv;
        }
    }
}
