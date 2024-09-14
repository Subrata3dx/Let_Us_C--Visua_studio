// MultiLevel_inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class FourWheeler
{
protected:
    string chasis, brake;
public:
    void getChasisData()
    {
        cout << "Enter the chasis type and brake type: ";
        cin >> chasis >> brake;
        cout<< endl;
        
    }

    void putChasisData()
    {
        cout << "Vehicle's chasis is made out of: " << chasis<<endl;
        cout << "Vehicle's brake type is: " << brake<<" brake type";
    }
};

class Engine :public FourWheeler
{
protected:
    string stroke, fuel;
public:
    void getStrokeData()
    {
        cout << "Type stroke data, enter 2 for two stroke and 4 for four stoke engine: ";
        cin >> stroke;
        cout << endl;
        cout << "Type fuel type, diesel or petrol: ";
        cin >> fuel;
        cout << endl;
    }
    void putStrokeData()
    {
        cout << "Vehicle's engine is: " << stroke<<" stroke"<<endl;
        cout << "Vehicle's fuel type is: " << fuel << endl;
    }
};

class VehicleType :public Engine
{
private:
    string vType;

public:
    void basicInfo()
    {
        cout << "Enter whether the vehicle is of transport or private category: ";
        cin >> vType;
        cout << endl;
    }
    void putbasicInfo()
    {
        cout << "Your vehicle's type is: " << vType<<endl;
        
    }
};



int main()
{
    VehicleType v1;
    
    v1.getChasisData();
    v1.getStrokeData();
    v1.basicInfo();
    cout << endl;
    cout << "Your vehicle's infomation:" << endl;
    v1.putChasisData();
    cout << endl;
    v1.putStrokeData();
    return 0;

}

