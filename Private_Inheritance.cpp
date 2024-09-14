// Private_Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Base {
public:
    void function_1()
    {
        cout << "Form Base's function_1";
    }

    void function_2()
    {
        cout << "Form Base's function_2";
    }
};


class Derived:private Base
{
public:
    Base::function_1;
};


int main()
{
    Derived d;
    d.function_1();
  //d.function_2();
    return 0;
    std::cout << "Hello World!\n";
}
