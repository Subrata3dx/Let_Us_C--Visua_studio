// virtualConsructors.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;

class Base
{
private:
    static int x;
public:
       
    int q;
    Base()
    {
        
        q = ++x;
        cout << endl << "Base constructor: " << q;
    }

    virtual void fun()
    {
        cout << endl << "Base fun of " << q;
    }

    virtual ~Base()  //or virtual ~Base() = 0;
    {
        cout << endl << "Base destructor: "<<q;
    }
    
};

/*
// when you declare a desructor as a pure virtual function, you must define a body for the destructor
Base::~Base()
{
    cout << endl << "Base destructor: " << q;
}
*/
int Base::x = 0;

class Child :public Base
{
private:
     static int y;
public:
    int p;

    Child()
    {
        p = ++y;
        cout << endl << "Child constructor: " << p;
        Base* b;
        b = this;
        b->fun(); //calling virtual function from constructor
    }

    void fun()
    {
        cout << endl << "Child fun of " << p;
    }

    ~Child()
    {
        Base* b;
        b = this;
        b->fun(); //calling virtual function from destructor
        cout << endl << "Child destructor: "<<p;
    }
};

int Child::y = 0;

int main()
{
    //Base b;
   // Child *ch =  new Child; //or new Child();
    //b = ch; //or just Base *b = new Child;
    //b->fun();
   // delete b;
    Child c;
 
    
}
