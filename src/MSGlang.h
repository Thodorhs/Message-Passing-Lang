#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

#define let auto
#define object (*new obj())
#define values (*new obj()),
#define key(s) obj(s)
enum types {ints,strings,doubles,bools,functions,objs};
class obj;

struct val{
    int i;
    string s;
    double d;
    bool b;
    function<bool(obj&)> f;
    obj* o;
};

class obj{

    public:
    int is_key=0; 
    vector<string> package;
    vector<struct val> value;
    vector<types> type;
    obj(){
        this->is_key=0;
    }
    obj(const char * s){
        this->package.push_back(string(s));
        this->is_key=1;
    }
    obj operator[](obj x){
        return x;
    }
    obj operator,(int x){
        int k = x;
        struct val strv;
        strv.i=k;
        string s = to_string(this->package.size());

        this->value.push_back(strv);
        this->type.push_back(ints);
        this->package.push_back(s);
        
        return *this;
    }
    obj operator,(string x){
        string k = x;
        struct val strv;
        strv.s=k;
        string s = to_string(this->package.size());

        this->type.push_back(strings);
        this->package.push_back(s);
        this->value.push_back(strv);
        return *this;
    }
    obj operator,(double x){
        double k = x;
        struct val strv;
        strv.d=k;
        string s = to_string(this->package.size());

        this->value.push_back(strv);
        this->type.push_back(doubles);
        this->package.push_back(s);
       
        return *this;
    }
    obj operator,(bool x){
        int k = x;
        struct val strv;
        strv.b=k;
        string s = to_string(this->package.size());

        this->value.push_back(strv);
        this->type.push_back(bools);
        this->package.push_back(s);
    
        return *this;
    }
    /*obj operator,(function<bool(obj&)> x){
        struct val strv;
        //strv.s=k;
        this->package.push_back(string("function"));
        //this->value.push_back(&x);
        this->type.push_back(functions);
        return *this;
    }*/
    obj operator,(obj x){
        obj k = x;
        struct val strv;
        strv.o=&k;
        if(x.is_key==0){
        string s("object");
        this->value.push_back(strv);
        this->type.push_back(objs);
        this->package.push_back(s);
        return *this;
        }
        for (size_t i = 0; i != k.package.size(); ++i){
            this->package.push_back(k.package[i]);
            this->value.push_back(k.value[i]);
            this->type.push_back(k.type[i]);
        }
        return *this;
    }
    obj operator=(int x){
        int k = x;
        struct val strv;
        strv.i=k;
        this->value.push_back(strv);
        this->type.push_back(ints);
        return *this;
    }
};




ostream& operator <<(ostream& out,  obj& x);
