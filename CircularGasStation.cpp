#include <iostream>
#include<vector>
using namespace std;
/*
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int remain = 0;
        int j, t;
        for (int i = 0; i < gas.size(); i++)
        {
            if (gas[i] + remain < cost[i])
                continue;

            j = t = i;
           // int remain = 0;
            while (gas[j] + remain >= cost[j])
            {
                remain = remain + gas[j] - cost[j];
                j++;

                if (t == j)
                    return t;

                if (j == gas.size())
                    j = 0;
            }
            i = t;
            remain = 0;
        }
        return -1;
    }
};
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0, totalcost = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalgas += gas[i];
            totalcost += cost[i];
        }
        if (totalcost > totalgas) {
            return -1;
        }
        int initialtankgas = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            initialtankgas += gas[i];
            initialtankgas -= cost[i];
            if (initialtankgas < 0) {
                start = i + 1;
                initialtankgas = 0;
            }
        }
        return start;
    }
};

int main()
{
    Solution so;
    vector<int>gas { 5, 1, 2, 3, 4 };
    vector<int>cost{ 4, 4, 1, 5, 1 };

    cout << so.canCompleteCircuit(gas, cost);
    return 0;
}

