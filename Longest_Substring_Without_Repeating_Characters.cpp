#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //int ch = s[i];
        unordered_map <char, int> umap;
        int j = 1;
        int count = 0;
        int t = 0;
        for (int i = 0; s[i] != '\0'; i++)
        {
            j=i+1;
            while (j == i + 1)
            {
                if (s[i] == '\0')
                    return count;
                
                if (umap.count(s[i]) != 1)
                {
                    t++;
                    count = max(count, t);
                    umap[s[i]] = i;
                    j++;
                }
               

                i++;


            }
            i--;
            i = umap[s[i]];
            t = 0;
            umap.clear();

        }

        return count;

    }
};

int main()
{
    string si = "pwwkew";
    Solution so;
   cout<< so.lengthOfLongestSubstring(si);
    return 0;
}