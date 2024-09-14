// Dimond_of_Death_Virtual_Base_Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class A
{
public:             //intentionally kept public

    int a;
    int x;

    void funA()
    {
        std::cout << "Value of class A: " << a;
    }

    A()
    {

    }

    A(int z)
    {
        a = z;
    }
};


class B1: virtual public  A     //to mitigate ambiguity issue we need to add the virtual keyword when inheriting a class.
{
public:                     //intentionally kept public
    int b1;
    void funB1()
    {
        std::cout <<'\n' << "Value of class B1: " << b1;
    }

    B1(int z)
    {
       
        b1 = z;
    }

};

class B2 : virtual public  A       //to mitigate ambiguity issue we need to add the virtual keyword when inheriting a class.
{
       
public:     //intentionally kept public
    int b2;
    void funB2()
    {
        std::cout << '\n' <<"Value of class B2: " << b2;
    }
   B2(int z)
   {
       b2 = z;
   }
};

class C :  public B1,  public B2
{

    
public:     //intentionally kept public
    int c;
    void funC()
    {
        std::cout << std::endl << "Value of class C: " << c;
    }
    C(int x, int y, int z, int a):A(x), B1(y), B2(z)
    {
        c = a;
    }
};

int main()
{
    C obj(100, 200, 300, 400);  //you can use without initialization by construtor
    //obj.c = 40;
   // obj.b2 = 30;
   // obj.b1 = 20;
  //obj.a = 10;
  obj.funA();
    obj.funB1();
    obj.funB2();
    obj.funC();
    std::cout<<'\n'<<sizeof(B1); //whenever the virtual keyword is used while inheriting a class, a pointer is added by compiler hence size becomes more (by one integer) than the expected size. 

}
