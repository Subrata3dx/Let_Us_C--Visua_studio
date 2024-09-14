#include<iostream>
#include<string>
#include<map>
using namespace std;


//solution from other guy in Leetcode
/*
class Solution {
public:
     bool wordPattern(string pattern, string s) {
        vector<string> v;
        int i=0;
        string temp="";
        while(i<s.size())
        {
            if(s[i]==' ')
            {
                v.push_back(temp);
                temp="";
            }
            else
            {
                temp+=s[i];
            }
            i++;
        }
        v.push_back(temp);
        if(v.size()!=pattern.size())
        return false;


        //creating mapssss
        unordered_map<char,string> m;
        set<string> used;
        for(int i=0;i<pattern.size();i++){
            if(m.find(pattern[i])!=m.end()){
                if(m[pattern[i]]!=v[i])
                return false;
            }
            else{
                if(used.count(v[i])>0)
                return false;
                m[pattern[i]]=v[i];
                used.insert(v[i]);

            }
        }
        return true;


    }
};
*/

//My solution
class Solution{

public:
 
 /*  
 // the following code does not work for same words for all the letters in pattern string

    bool wordPattern(string pattern, string s) {

        map<char, string> myMap;
        // map<string, char> myMap1;

        int  WordCount = 0, j = 0; //to count number of words in s

        for (int i = 0; i < pattern.length(); i++)
        {
            string temp = "";
            while ((j < s.length()) && (s[j] != ' '))
                temp = temp + s[j++];

            if (j <= s.length())
                WordCount++;

            if (myMap[pattern[i]] == temp || myMap[pattern[i]] == "")
                myMap[pattern[i]] = temp;
            else
                return false;
            j++;
        }

        if (j < s.length() || WordCount < pattern.length())
            return false;

        return true;

*/
 bool wordPattern(string pattern, string s) {

        map<char, string> myMap;
        map<string, char> myMap1;

        int  WordCount = 0; //to count number of words in s

        int j = 0;
        for (int i = 0; i < pattern.length(); i++)
        {
            string temp = "";
            while ((j < s.length()) && (s[j] != ' '))
                temp = temp + s[j++];

            if (j <= s.length())
            WordCount++;

            string temp2 = myMap[pattern[i]]; //for an unmaped location it returns "".
            if (temp == temp2 || temp2 == "") //if pattern[i] alredy has a word, it compares with the current word in temp.  
                myMap[pattern[i]] = temp;
            else
                return false;

            char x = myMap1[temp]; //for an unmaped location it returns '\0'.
            if (x == '\0' || x == pattern[i]) //if pattern[i] alredy has a character, it compares with the current character in x. 
                myMap1[temp] = pattern[i];
            else
                return false;

            j++;
        }

        if (j < s.length() || WordCount < pattern.length())  //checks whether number of characters and words are not matching
            return false;

        return true;

    }
};




int main()
{
    Solution so;
    string pattern = "abba"; //abba // abba // ab //ab
    string s = "cat cat cat cat"; //dog cat cat dog //cat cat cat cat // cat cat cat//dog
    cout<<so.wordPattern(pattern, s);

    return 0;
}
