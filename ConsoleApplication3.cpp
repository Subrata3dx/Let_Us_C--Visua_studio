// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class A
{
    int x;
public:
    A() :x(10) {}
   virtual void show()
    {
        cout << "x = " << x;
    }

};

class B: public A
{
    int y;
public:
    B() :y(40) {}

    void show()
    {
        cout << "y = " << y;
    }

};



int main()
{
    A* a = new A();
    B* b = dynamic_cast<B*>(a);
    if (b == nullptr)
       return 0;
      
    b->show();
    return 0;

}
