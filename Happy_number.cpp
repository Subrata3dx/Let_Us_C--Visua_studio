// Happy_number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    

    bool isHappy(int n) {
        int sum = 0, k, j = 0;
        map<int, int> map1;
        while (n < 4294967296 - 1)
        {
            //k = n;
            //j = 0;
            //while(k>=1)
            //{
            int m = n % 10;
            map1[j++] = (m * m);
            n = n / 10;
            //}
            if (n < 1)
            {
                for (int i = 0; i < map1.size(); i++)
                    sum = sum + map1.at(i);
                if (sum == 1)
                    return true;
                else
                    map1.clear();

                n = sum;
                sum = 0;
                j = 0;
            }

        }
        return false;
    }
    
};


int main()
{
    Solution so;
    cout<<so.isHappy(19);
    return 0;
}

