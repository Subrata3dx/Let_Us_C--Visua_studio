// CopyConstructors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;

class Inverter
{
    int battQty;
    int KVA;
    int size;
    char* brand=NULL;

public:
    Inverter(const char* br = NULL, int bq =0, int kv=0)
    {
        size = strlen(br);
        brand = new char[size+ 1];
        memcpy(brand, br, (size +1));
        battQty = bq;
        KVA = kv; 
        
    }

   
    void show()
    {
        cout << endl << "Inverter brand : " << brand;
        cout << endl<<"No.of battery : " << battQty;
        cout << endl << "KVA of inverter : " << KVA;
        //cout << endl << "Manufacture year : " << *year;

    }
    
    void changeBrand(const char *br = NULL)
    {
        delete[]brand;
        size = strlen(br);
        brand = new char[size + 1];
        memcpy(brand, br, (size + 1));
    }

    Inverter(Inverter&);

    ~Inverter()
    {

    }
};

Inverter::Inverter(Inverter& inv) //remove this copy constructor to see the effect
{
    battQty = inv.battQty;
    KVA = inv.KVA;
    size = inv.size + 1;
    brand = new char[size];
    memcpy(brand, inv.brand,(size) );
    
    
}


int main()
{
    int year = 2008;
    int time = 2010;
    Inverter inv1("Luminous", 2, 15);
    Inverter inv2("Amaron", 1, 10);
    
    
    cout << endl << "Inv 1";
    inv1.show();
    cout << endl << "Inv 2";
    inv2.show();
    
    Inverter x = inv1;
    
    cout << endl<<endl << "After copying Inv1 to x, status of x:";
    x.show();
    
    x.changeBrand("Exide");
    cout << endl << endl << "After changing Inv x name, status of inv1:";
    inv1.show();

    cout << endl << "Status of Inv x:";
    x.show();

    inv1.changeBrand("V-guard");
    cout << endl << endl << "Changing brand of Inv1 and see statuses:";
    cout << endl << "Inv x";
    x.show();
    cout << endl << "Inv1";
    inv1.show();
    return 0;
}
