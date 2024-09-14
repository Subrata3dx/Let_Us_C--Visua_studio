// AbsoluteToCanonicalPath.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

class Canonical
{
public:

    string simply(string path)
    {
        stack<string> st;
        int size = path.length();
        for (int i = 0; i < size; i++)
        {
            if (path[i] == '/')
                continue;
            string temp = "";
            while (i < size && path[i] != '/')
            {
                temp = temp + path[i];
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

        string ans = "";
        while (!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if (ans.length() == 0)
            return "/";

        else
            return ans;
    }
    
};


int main()
{
    Canonical c;
    cout<<c.simply("/.../hello//world/../guru/.");
    return 0;

}
