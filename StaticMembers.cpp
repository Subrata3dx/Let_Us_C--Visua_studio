// StaticMembers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;



class CheckStatic {
private:
     static int count;
    

public:
     int lcount;
     
     static void increase()
    {
        count++;
        
    }

     int* fun()
     {
        static int  x = 10;
         return &x;
     }

    static void decrease()
    {
        count--;
    }

   

    CheckStatic()
    {
        increase();
        lcount = count;
        std::cout << std::endl<<"Object created: " << lcount;
    }

    ~CheckStatic() 
    {
        decrease();
        std::cout << std::endl<<"Object deleted: "<<lcount; 
    }
};

int CheckStatic::count = 0;
//int CheckStatic::lcount = 0;


int main()
{
    //for (int i = 0; i < 5; i++)
    //{
        
        CheckStatic* ptr1 = new CheckStatic();
        CheckStatic* ptr2 = new CheckStatic();
        CheckStatic* ptr3 = new CheckStatic();
        CheckStatic* ptr4 = new CheckStatic();
        delete ptr1;
        
        delete ptr3; delete ptr2;
        delete ptr4;

   // }
        int x = 1000;
        int* p = &x;

    CheckStatic obj;
    //CheckStatic *ptr = new CheckStatic();

    CheckStatic::increase();
    cout << endl<<obj.lcount;

    //a different use of static keyword and reference 
    *obj.fun() = 20; //it assigns 20 to x using the returned reference
    cout <<endl<< *obj.fun();
    cout << endl << *p;
    
   
}
