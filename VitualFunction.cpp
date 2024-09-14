// VitualFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Base
{
private:
    int age;

public:
    Base()
    {
        age = 100;
    }

    virtual int  getAge() = 0;
   

};

class Father:public Base
{
private:
    int age;

public:
    Father()
    {
        age = 40;
    }
    int getAge()
    {
        return age;
    }
};

class Boy : public Base
{
private:
    int age;

public:
    Boy()
    {
        age = 10;
    }

    int getAge()
    {
        return age;
    }
    
};

class subrata :public Base
{
private:
    string name;
    char identity[1];
    int age;

public:
    subrata()
    {
        name = "Subrata";
        *identity = 'M';
        age = 33;
    }

    void other()
    {
        cout << "Name: " << name;
        cout << "\t" << identity[0]<< endl;
    }

    int getAge()
    {
        return age;
    }


};



int main()
{
    Base* b;//, B;

    Boy b1;
    Father f;
    subrata s;
    b = &b1; //upcasting 

   // cout << "Base's age: "<<B.getAge() << endl;
    b = &f;
    cout << "Father's age: "<<b->getAge()<<endl;
    cout<< "Son's age: "<<b1.getAge()<<endl;
    b = &s;
    cout << "Subrata's details: " <<"\nAge:"<< b->getAge() << "\t";
    s.other();


    return 0;
}
