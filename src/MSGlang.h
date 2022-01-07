#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

#define let auto
#define object (*new obj())
#define values (*new obj()),

class obj{

    public:
    vector<string> package;

    obj operator[](obj x){
        return x;
    }
    obj operator,(int x){
        string s = to_string(x);
        this->package.push_back(s);
        return *this;
    }
    obj operator,(string x){
        this->package.push_back(x);
        return *this;
    }
    obj operator,(double x){
        string s = to_string(x);
        this->package.push_back(s);
       
        return *this;
    }
    obj operator,(bool x){
        string s = to_string(x);
        this->package.push_back(s);
        
        return *this;
    }
    /*obj operator,(function x){
    }*/
    /*obj operator,(obj x){
    }*/
};

void print_obj(obj x);

