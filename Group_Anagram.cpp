
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map <string, vector<string>> map1;
        int s = strs.size();

        for (auto x : strs)
        {
            string temp = x;
            sort(temp.begin(), temp.end());
            map1[temp].push_back(x);

        }

        vector <vector<string>> ans;
        for (auto x : map1)
            ans.push_back(x.second);

        return ans;
    }
};

int main()
{
    Solution so;
    
    vector <string> v {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> k;
    k = so.groupAnagrams(v);
    for (auto x : k) {
        for (auto y : x)
        {
            cout << y<<", ";
        }
           
        cout << "|";
    }
       
}


