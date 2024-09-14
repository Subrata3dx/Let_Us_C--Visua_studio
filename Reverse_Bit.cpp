// Reverse_Bit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t ans = 0;
        for (int i = 0; i < 32; i++)
        {
            ans = ans * 2 + n % 2;
            n = n / 2;
        }
        return ans;
    }
};

int main()
{
    Solution s;;
    uint32_t x = 10;
    
    cout << s.reverseBits(x);

}