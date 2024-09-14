// Class_and_stucture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Test
{

public:         //Try removing public keyword
    int a;
    int  fun_Test()
    {
        return a = 40;
    }
};

struct Check
{
    int b;
    int fun_Check()
    {
        return b = 50;
    }
};

int main()
{
    Test T;
    Check C;
    //C.fun_Check();
    //T.fun_Test();
  std::cout << "\nValue from Test: " <<T.fun_Test();    //By default, the members of a class are private. Whereas, the members of a structure are public. This is the only difference between a class and structure.
   std::cout << "\nValue from Check: " << C.fun_Check();
    return 0;
}



