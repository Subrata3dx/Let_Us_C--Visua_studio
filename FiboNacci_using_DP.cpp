// FiboNacci_using_DP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int>arr; //array also could be used, then we need to assign the elements of the array with a loop


int findFibo(int n)
{
    if (arr[n] != -1)
        return arr[n];
   
    else
       arr[n] = findFibo(n - 1) + findFibo(n - 2);

    return arr[n]; //returns after calculation
}

int main()
{
    arr.assign(21, -1); //assigning 21 elements of arr with -1
    arr[0] = 0; //assigning first element with 0
    arr[1] = 1; //assigning first element with 1
    cout<<findFibo(20);
    return 0;
}




