
#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;
class Solution{
public:
    int findMinArrowShots(vector<vector<int>>&points) {
        sort(points.begin(), points.end());
        int count = 1, i = 0;
       int temp = points[0][1];

        while (i < points.size())
        {
            if (points[i][0] > temp)
            {
                count++;
                temp = points[i][1];
                i++;
                continue;
            }

            if (temp > points[i][1])
            {
                temp = points[i][1];
            }

            i++;
        }
        return count;
    }
};

int main()
{
    vector<vector<int>>xyz{ {1, 10}, {4, 10}, {6, 9}, {3, 9}, {6, 7}, {8, 12}, {9, 12} };
    Solution so;
    cout << so.findMinArrowShots(xyz);
}