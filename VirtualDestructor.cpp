// VirtualDestructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Abs
{
public:
    void virtual test() = 0;
};

class Base
{
    
public:
    Base()
    {
        cout << endl << "Base constructor";
    }

     virtual void fun() = 0; //pure virtual function
 

   virtual ~Base() 
    {
        cout <<endl<< "Base destructor";
    }
};

class Derived : public Base, public Abs


{
    
public:
    Derived()
    {
        cout << endl << "Derived constructor";
    }

    void fun()
    {
        cout << endl << "Derived fun() called";
    }

    void test()
    {
        cout << endl << "Derived test() called";
    }

    ~Derived()
    {
        cout << endl << "Derived destructor";
    }
};



int main()
{
 
    
    Derived *d = new Derived;
    Base* p = d;
    p->fun();
    d->test();
    delete p;
   
}

