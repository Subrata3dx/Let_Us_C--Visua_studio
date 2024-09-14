#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        string res;
        stack <string> st;
        for (int i = 0; i < path.length(); i++)
        {
            char ch = path[i];
            if (path[i] == '/')
                continue;

            string temp;
            while (i < path.size() && path[i] != '/')
            {
                temp += path[i];
                i++;
            }

            if (temp == ".")
                continue;

            else if (temp == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else
                st.push(temp);
        }

        while (!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }

        if (res.size() == 0)
            return "/";

        return res;
    }

};
int main()
{
    string str = "//home./a/.//d";
    Solution so;
    cout<<so.simplifyPath(str);
    return 0;
}
