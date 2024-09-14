// SubstringWithConcatenationOfAllWords.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;
/*
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int>um, um1;
        /*for (int i = 0; i < words.size(); i++)
        {
            if (um.find(words[i]) == um.end())
                um.insert({ words[i], 1 });
            else
                um[words[i]]++;
        }

        vector<int>v;
        int wSize = (words.size() * words[0].size());
        if (wSize > s.length())
            return v;

        bool k = true;

        for (int i = 0; i <= s.length() - wSize; i++)
        {

            string sub = s.substr(i, wSize);
            //um1 = um;

            vector<string> v1 = words;

            vector<string>::iterator it;

            int len = words[0].size();
            for (int j = 0; j < sub.length(); j = j + len)
            {
                string subW = sub.substr(j, len);
            /*    if (um1.find(subW) != um1.end())
                    um1[subW]--;
            

                it = find(v1.begin(), v1.end(), subW);
                if(it!=v1.end())
                v1.erase(it);
            }
            for (auto& x:um1)
            {
                if(x.second != 0)                
                    k = false;

            }
            if (v1.size() == 0)
                v.push_back(i);

            /*if (k)
            v.push_back(i);

            for (auto& x : um)
            {
                x.second = 0;

            }
            
            //k = true;
        }

        return v;
    }
};
*/

/*
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int>v;
        int wSize = (words.size() * words[0].size());
        if (wSize > s.length())
            return v;


        for (int i = 0; i <= s.length() - wSize; i++)
        {

            string sub = s.substr(i, wSize);

            vector<string> v1;

            //vector<string>::iterator it;

            int len = words[0].size();
            for (int j = 0; j < sub.length(); j = j + len)
            {
                string subW = sub.substr(j, len);

                /* it = find(v1.begin(), v1.end(), subW);
                 if(it!=v1.end())
                 v1.erase(it);
                 else
                 break;
                 */

           //     if (find(words.begin(), words.end(), subW) != words.end())
            //        v1.push_back(subW);

           //     else
            //        break;
           // }

           // if (v1 == words)
             //   v.push_back(i);


      //  }

      //  return v;
  //  }
//};


class Solution {
public:

    vector<int> findSubstring(string str, vector<string>& words) {
        int len = words[0].length();

        unordered_map<string, int> contain;
        for (string s : words) contain[s]++;

        vector<int> res;
        for (int j = 0; j < len; j++) 
        {
            unordered_map<string, int> found;
            int st = j;
            for (int i = 0 + j; i < str.size() - len + 1; i += len) 
            {
                string curr = str.substr(i, len);
                if (contain.find(curr) != contain.end()) 
                {
                    found[curr]++;
                    while (found[curr] > contain[curr]) 
                    {
                        found[str.substr(st, len)]--;
                        st += len;
                    }
                    int size = (i - st + len) / len;
                    if (size == words.size()) {
                        //cout << j << " " << st << " " << i << endl;
                        res.push_back(st);
                    }
                }
                else {
                    found.clear();
                    st = i + len;
                }
            }
        }

        return res;
    }

};

int main()
{
    Solution so;
    string t = "wordgoodgoodgoodbestword";
    vector<string> w = { "word","good","best"};
    vector<int>vi;
    vi = so.findSubstring(t, w);
    for (auto x : vi)
    {
        cout << x << " ";
    }
    return 0;

    
}
