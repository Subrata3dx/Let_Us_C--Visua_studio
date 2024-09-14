// Multiple_class_uses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BedRoom.cpp"
using namespace std;


class Kitchen
{
    int gasStove, gasCylinder, cooker;

public:
    Kitchen()
    {
        gasStove = 1;
        gasCylinder = 1;
        cooker = 1;
    }

    void updateGasCylinder(int qty)
    {
        gasCylinder = qty;
    }

    void updateGasStove(int qty)
    {
        gasStove = qty;
    }

    void getKitchenInfo(void)
    {
        cout << "The kitchen has the following items.\n";
        cout << "Gas stove: " << gasCylinder<<endl;
        cout << "Gas cylinder: " << gasCylinder << endl;
        cout << "Cooker: " << cooker<<endl;
                
    }

    
};


int main()
{
    BedRoom B;
    Kitchen K;

    K.updateGasCylinder(2);
    B.updateItems(2, 1);
    K.getKitchenInfo();
    B.getItems();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
