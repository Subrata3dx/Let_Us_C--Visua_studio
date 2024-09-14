// GasStation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include <vector>
using namespace std;


class GasStation
{
private:
    int totalGas, totalCost, currentGas;

    
public:


    GasStation()
    {
        totalGas = 0, totalCost = 0, currentGas = 0;
    }
    
    int checkStation(vector<int>& gas, vector<int>& cost)
    {
        int size = gas.size();

        int stationIndex = 0;
        for (int station = 0; station < size; station++)
        {
            totalGas += gas[station];
            totalCost += cost[station];

            currentGas = gas[station] - cost[station];
            if (currentGas < 0)
            {
                stationIndex = station + 1;
                currentGas = 0;
            }
        }

        return totalGas < totalCost ? -1 : stationIndex;
    }
};
int main()
{
    vector<int> gas =  { 2, 3, 3, 1, 5 };
    vector<int> cost = { 3, 4, 2, 3, 2 };

    GasStation *g = new GasStation();
    cout << g->checkStation(gas, cost);
    return 0;
}
