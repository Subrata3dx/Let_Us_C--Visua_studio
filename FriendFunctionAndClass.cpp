// FriendFunctionAndClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
class B;
char z[] = {'m', 'a', 'n'};
char* y = z;

string s1 = "1234";
string s2 = " Gouranga";
string s3 = s1.append(s2);
int xyz = stoi(s1);


int x = 555;


class A {
private:
    string m = "Ram";
protected:
    int n = 500;

public:
    void test()
    {
        cout << m << " " << n;
    }

    friend class Dxdz;
    friend void f(A&, B&);
};

class Dxdz 
{
public:
    void foo(A& a)
    {
        cout<<endl<<a.m;
    }
};

class B {
private:
    int m = 100;
protected:
    string n = " Sita";

public:
    void test()
    {
        cout << m << " " << n;
    }

    friend void f(A&, B&);
};

void f(A &a, B &b)
{
    string s = a.m + b.n; //adding two string of two different classes of different access specifier
    cout << s;
}


class TY
{
public:
    virtual void hi() = 0;
    virtual void hello()
    {
        cout <<endl<< "Hello from TY";
    }
};

class PY : public TY
{
public:
    void hi()
    {

    }

    void hello()
    {
        cout << endl<< "Hello from PY";
    }
};

int main()
{
    int x = 40;
    A a;
    B b;
    f(a, b);
    cout << endl<<"x = " << ::x; //accessing global variable
    cout << endl << "z = " << ::z;
    cout << endl << "string = " << ::s3;
    Dxdz d;
    d.foo(a);
    TY* ty = new PY;
    
    
    ty->hello();
    return 0;
}

