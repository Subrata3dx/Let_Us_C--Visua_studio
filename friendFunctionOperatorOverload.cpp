//friend function with operator overload

#include <iostream>
using namespace std;
class A
{
    int a, b;
public:
    void setData(int x, int y);
    
    void getData()
    {
        cout << "A = " << a << endl;
        cout << "B = " << b;
    }
    A friend operator +(A, A);
    void friend operator --(A&);
    //A freiend operator --(A);
    
};

void A::setData(int x, int y)
{
    a = x, b = y;
}


void operator --(A &x)
{
  
      --x.a;
      --x.b;
  
}

/*
A operator --(A x)
{
    A temp;
     temp.a = --x.a;
     temp.b = --x.b;
   return temp;
}
*/

 A operator +(A x, A y)
{
    A temp;
    temp.a = x.a + y.a;
    temp.b = x.b + y.b;
    return temp;
}


int main()
{
    A a1, b1, c1, d1;
    //B b1;
    
    a1.setData(10, 20);
    b1.setData(30, 40);
    d1.setData(1, 2);
    c1 = a1 + b1;
    c1.getData();
    --d1;
    //d1=--d1;
    cout << endl;
    d1.getData();
   
  
}

