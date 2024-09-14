// Overloading_newOperator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<new.h>
#include<stdlib.h>
using namespace std;

const int MAX = 5;
const int FREE = 0;
const int OCCUPIED = 1;

void memwarning()
{
    cout << endl << "Free store is out of memory.";
    exit(0);
}

class OvrldNew 
{
private:
    int age;
    char name[40];
    float sal;

public:
    void* operator new(size_t bytes);
    void operator delete(void* q);
    void setData(const char*, int, float);
    void showData();
    ~OvrldNew();

};

struct Pool
{
    OvrldNew obj;
    int status;
};

int flag = 0;
struct Pool* p = NULL;

void* OvrldNew::operator new (size_t sz)
{
    
    
    if (flag == 0)
    {
        p = (Pool*) malloc(sz * MAX);
        if (p == NULL)
            memwarning();

        for (int i = 0; i < MAX; i++)
        {
            p[i].status = FREE;
        }
        flag = 1;
        p[0].status = OCCUPIED;
        return &p[0].obj;
    }

    else
    {
        for (int i = 0; i < MAX; i++)
        {
            if (p[i].status == FREE)
            {
                p[i].status = OCCUPIED;
                return &p[i].obj;
            }
        }
        memwarning();
    }

}

void OvrldNew::operator delete(void* q)
{
    if (q == NULL)
        return;
    for (int i = 0; i < MAX; i++)
    {
        if (q == &p[i].obj)
        {
            p[i].status = FREE;
            strcpy_s(p[i].obj.name, "");
            p[i].obj.age = 0;
            p[i].obj.sal = 0.0;
        }
    }
}

void  OvrldNew::setData(const char* n, int a, float s)
{
    strcpy_s(name, n);
    age = a;
    sal = s;
}

void OvrldNew::showData()
{
    cout << endl << name << " " << age << " " << sal;
}

OvrldNew::~OvrldNew()
{
    cout << endl << "Reached destructor";
    free(p);
}



int main()
{
    void memwarning();
    try {
        set_new_handler(memwarning);
    }
    catch(exception e)
    {
        cout << "exception";
    }

    OvrldNew* e1, * e2, * e3, * e4, * e5, * e6;
    e1 = new OvrldNew;
    e1->setData("Aprameya", 2, 22.22);
    
    e2 = new OvrldNew;
    e2->setData("Aditya", 5, 55.55);
    
    e3 = new OvrldNew;
    e3->setData("Ayush", 10, 10.10);
    
    e4 = new OvrldNew;
    e4->setData("Anisha", 18, 18.18);
    
    e5 = new OvrldNew;
    e5->setData("Megha", 11, 11.11);
    
    //e1->showData();
   // e2->showData();
   // e3->showData();
   // e4->showData();
   // e5->showData();

    //delete e4;
    //delete e5;

   // e4->showData();
   // e5->showData();

   // e4 = new OvrldNew;
    //e5 = new OvrldNew;

    //now exhaust the store
   // e6 = new OvrldNew;
   // e6->setData("Priyam", 8, 7777);

    cout << endl << "Done.";
    return 0;

}



