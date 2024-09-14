#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < tokens.size(); i++)
        {
            string str = tokens[i];
            if (str == "+" || str == "-" || str == "*" || str == "/") //rember not to use '+' or '-' as these annotation is used for character
            {
                int res;
                int var1 = st.top();
                st.pop();
                int var2 = st.top();
                st.pop();

                if (str == "+")
                    res = var2 + var1;
                else if (str == "-")
                    res = var2 - var1;
                else if (str == "*")
                    res = var2 * var1;
                else if (str == "/")
                    res = var2 / var1;

                st.push(res);
            }

            else
            {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};

int main()
{
    vector <string> rpn{ "4","13","5","/","+" };
    Solution so;
    cout << so.evalRPN(rpn);
    return 0;
}

