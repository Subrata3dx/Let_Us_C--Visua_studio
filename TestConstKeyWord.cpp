// TestConstKeyWord.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int x({ 10 });
   int* const y = &x; 
   int t = 0;
   int age[] = { 10, 20, 30 };
   int* ptr = age;
  
 //  int reverse(int &, int &);
  
 
//x = 10;

   void reverse(int* a, int* b)
   {
       int temp = *a;       
       a = b;
       *b = temp;
   }

int main()
{
    int x = 10;
    int y = 15;

    int& c = x;

    shared_ptr <int> p1 (new int(10));
    shared_ptr<int> p2; 
    //p2.make_shared(new int(20));
    p2 = p1;
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    p1.reset();
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    cout<<p2.get();

    /*
    reverse(&x, &y);
    cout << x << endl << y;
    /*int x = sizeof(age) / sizeof(age[0]);
    for (int i = 0; i < x; i++)
    {
        cout << *ptr++<<" ";

    }
    
    cout << endl;
    cout << c;
    */


   
}

