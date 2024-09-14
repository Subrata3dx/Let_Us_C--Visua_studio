// classAndOperatorOverloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class overload
{
private:
    int count;

public:
    overload()
    {
        count = 1;
    }

    overload(int val)
    {
        count = val;
    }

   /* void operator++ () //This method can be used if the icremented value is not assigned to any other objects    
    {
        ++count;
        
    }

    */

   overload operator++()
    {
        ++count;
        return overload(count);
    }

    /*// the above function can also be written as below.
     overload & operator++ ()
    {
        ++count;
        return *this;
    }
    */

    void showdata()
    {
        cout << count;
    }
};

int main()
{
    overload a, b, c;
    cout << endl << "a= ";
    a.showdata();

    ++a;
    cout << endl << "a= ";
    a.showdata();

    ++b;
    cout << endl << "b = ";
    b.showdata();
    

    cout << endl << "c = ";
    c = ++a;
    c.showdata();

    return 0;
}

