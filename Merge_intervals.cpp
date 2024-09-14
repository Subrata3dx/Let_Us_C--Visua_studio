#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int k;
        sort(intervals.begin(), intervals.end()); //this sorts the vector elements according to the first element's value of the internal vector.
        vector<vector<int>> output;
        for (auto interval : intervals) {
            
            if (output.empty() || output.back()[1] < interval[0]) {
                output.push_back(interval);
            }

            else {
                output.back()[1] = max(output.back()[1], interval[1]);
            }
            k = output.back()[1]; // I added this to see what output.back() returns. The back() function returns the reference of last element of a vector.
            
        }
        return output;
    }
};

/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end());

        vector<vector<int> > v;
        vector<int> temp = intervals[0];
        for(auto it : intervals)
        {
             if(temp[1]>=it[0])
             {
                temp[1]=max(it[1],temp[1]);
             }
             else
             {
                v.push_back(temp);
                temp = it;
             }
         }v.push_back(temp);
        return v;
    }
};
*/


/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1]>=intervals[i][0])
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};
*/

int main()
{
    vector<vector<int>> intervals{ {1,3}, {8, 10}, {2, 6}, {15, 18} };
    Solution so;
    intervals = so.merge(intervals);
    for (auto x : intervals)
        cout << x[0]<<" "<<x[1]<<",";


}

