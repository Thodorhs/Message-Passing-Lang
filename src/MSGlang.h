#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

#define let auto
#define object (*new obj())
#define values (*new obj()),
#define key(s) obj(s)
#define ref(o) &o
#define func(str) key(str) = lambda
#define lambda []
#define none NULL
#define nl endl
enum types {ints,strings,doubles,bools,functions,objs};
class obj;

struct val{
    int i;
    string s;
    double d;
    bool b;
    function<bool(obj& a)> f;
    obj* o;
};

class obj{

    public:
    obj *to_eval;
    const char * func_to_call="";
    int called_for_inspect=0;
    const char *change_id;
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
        change_id=s;
    }
    obj operator[](obj x){
        return x;
    }
    obj& operator[](const char * x){
        called_for_inspect=1;
        change_id=x;
        return *this;
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
    obj operator,(const char * x){
        string k = string(x);
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
    obj& operator,(obj& x){
        obj *k;
        k = &x;
        struct val strv;
        strv.o=k;
        if(x.is_key==0){
        cout<<"splats"<<endl;
        string s("object");
        this->value.push_back(strv);
        this->type.push_back(objs);
        this->package.push_back(s);
        return *this;
        }
        for (size_t i = 0; i != k->package.size(); ++i){
            this->package.push_back(k->package[i]);
            this->value.push_back(k->value[i]);
            this->type.push_back(k->type[i]);
        }
        return *this;
    }
    obj& operator=(int x){
        int k = x;
        struct val strv;
        strv.i=k;
        if(this->called_for_inspect){
            for (size_t i = 0; i != this->package.size(); ++i){
                if(this->package[i].compare(string(change_id))==0){
                    this->value[i]=strv;
                    this->type[i]=ints;
                    called_for_inspect=0;
                    return *this;
                }
            }
        }
        this->value.push_back(strv);
        this->type.push_back(ints);
        return *this;
    }
    obj& operator=(double x){
        double k = x;
        struct val strv;
        strv.d=k;
        if(this->called_for_inspect){
            for (size_t i = 0; i != this->package.size(); ++i){
                if(this->package[i].compare(string(change_id))==0){
                    this->value[i]=strv;
                    this->type[i]=doubles;
                    called_for_inspect=0;
                    return *this;
                }
            }
        }
        this->value.push_back(strv);
        this->type.push_back(doubles);
        return *this;
    }
    obj& operator=(const char * x){
        string k = string(x);
        struct val strv;
        strv.s=k;
        if(this->called_for_inspect){
            for (size_t i = 0; i != this->package.size(); ++i){
                if(this->package[i].compare(string(change_id))==0){
                    this->value[i]=strv;
                    this->type[i]=strings;
                    called_for_inspect=0;
                    return *this;
                }
            }
        }
        this->value.push_back(strv);
        this->type.push_back(strings);
        return *this;
    }
    obj& operator=(bool x){
        bool k = x;
        struct val strv;
        strv.b=k;
        if(this->called_for_inspect){
            for (size_t i = 0; i != this->package.size(); ++i){
                if(this->package[i].compare(string(change_id))==0){
                    this->value[i]=strv;
                    this->type[i]=bools;
                    called_for_inspect=0;
                    return *this;
                }
            }
        }
        this->value.push_back(strv);
        this->type.push_back(bools);
        return *this;
    }
    obj& operator=(struct val strv){
            for (size_t i = 0; i != this->package.size(); ++i){
                if(this->package[i].compare(string(change_id))==0){
                    switch(this->type[i]){
                    case 0:
                    this->value[i]=strv;
                    this->type[i]=ints;
                        break;
                    case 1:
                    this->value[i]=strv;
                    this->type[i]=strings;
                        break;
                    case 2:
                    this->value[i]=strv;
                    this->type[i]=doubles;
                        break;
                    case 3:
                    this->value[i]=strv;
                    this->type[i]=bools;
                        break;
                    default:
                    break;
                }
            }
        }
    return *this;
    }
    obj& operator=(function<bool(obj& a)> fun){
        struct val strv;
        strv.f=fun;
        cout<<"im here"<<endl;
        if(this->is_key){
            for (size_t i = 0; i != this->package.size(); ++i){
                cout<<"im here"<<endl;
                if(this->package[i].compare(string(change_id))==0){
                    cout<<"im here"<<endl;
                    this->value[i]=strv;
                    this->type[i]=functions;
                    cout<<"im here"<<endl;
                    return *this;
                }
            }
        }
    return *this;
    }
    void operator <<(obj& x){
        this->to_eval=&x;
        for (size_t i = 0; i != this->package.size(); ++i){
            if(this->package[i]==string(x.func_to_call)){
                this->value[i].f(x);
            }
        }
    }
    void call(char *c){
        this->func_to_call=c;
    }
    vector<struct val>  args_list(){
        return this->value;
    }
    void eval(char * ss){
        for (size_t i = 0; i != this->package.size(); ++i){
            if(this->to_eval->package[i]==string(ss)){
                this->to_eval->value[i].f(*this);
            }
        }
    }
    bool eval_cond(char * ss){
        for (size_t i = 0; i != this->package.size(); ++i){
            if(this->to_eval->package[i]==string(ss)){
                return this->to_eval->value[i].f(*this);
            }
        }
        return false;
    }
};

struct val input(const char *s);

ostream& operator <<(ostream& out,  obj& x);
