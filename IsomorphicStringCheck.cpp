
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        vector<bool> s1(256, 0);
        vector<bool> t1(256, 0);
        vector<int> test(256, -1);

        for (int i = 0; i < s.length(); i++)
        {
            if (s1[s[i]] == 1 || t1[t[i]] == 1)
            {
                if (test[s[i]] != t[i] - 'a')
                    return false;
            }

            else
            {
                s1[s[i]] = 1;
                t1[t[i]] = 1;
                test[s[i]] = t[i] - 'a';
            }

        }
        return true;
    }
};

*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp, mp2;
        for (int i = 0; i < s.length(); ++i) {

           
            if (mp[s[i]] && mp[s[i]] != t[i]) //precedence of != is more than && // mp[s[i]] checks if there is any value for s[i] in the map mp, also maps the key s[i] to 0
                /*
                mp[s[i]] checks if the character s[i] is a key in the map mp.
                mp[s[i]] != t[i] checks if the character s[i] in the map mp is not equal to the character t[i].
                
                So, the condition if (mp[s[i]] && mp[s[i]] != t[i]) is true if:

                - The character s[i] exists as a key in the map mp.
                - The character s[i] in the map mp is not equal to the character t[i] at the same position.
                In other words, this code is checking if the character at position i in the s string exists in the map mp and is not the same as the character at position i in the t string.
                */
                
                return false;
            if (mp2[t[i]] && mp2[t[i]] != s[i])
                return false;
            mp[s[i]] = t[i];
            mp2[t[i]] = s[i];
           
        }
        return true;
    }
};

int main()
{
    string s = "bll";//"12";
    string t = "ptm";//"\u0067\u0067";
    Solution so;
    bool f;
    f = so.isIsomorphic(s, t);
    cout << f;
    return 0;
    
}