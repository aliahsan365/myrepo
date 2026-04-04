//Memory Leak checks.
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>


#include <iostream>
#include <string>
using namespace std;



class Parent {
public:
    virtual void printName() = 0;
    virtual ~Parent() {
        cout << "Deleting parent..." << endl;
    }
};

class Son : public Parent {
private:     
    string _name;
public:
    
    Son(string name) {
        cout << "A Son is created " << endl;
        _name = name;
    }
    
    void printName() {
        cout << "Son's Name is " << _name << endl;    
    }

    virtual ~Son() {
        cout << "Deleting son..." << endl;
    }
};


class Daugther : public Parent {
private: 
    string _name;
public:
    Daugther(string name) {
        cout << "A Daugther is created " << endl;
        _name = name;
    }
    void printName() {
        cout << "Daugther's Name is " << _name << endl;
    }
    virtual ~Daugther() {
        cout << "Deleting Daugther..." << endl;
    }
};

//IMPORTANT STUFF...
//which printName() !!?? It's solved at runtime. 
void function(Parent* p) {
    p->printName(); // printName() from the Son's object is called.
}

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Parent* b = new Son("ali");
    function(b);
    delete b; // a virtual destructor is need to avoid memory leaks.
}