#include <bits/stdc++.h>
using namespace std;
class Stack
{
    stack<char> s;

public:
    bool validParenthesis(string str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '{' || str[i] == '(' || str[i] == '[')
            {
                s.push(str[i]);
            }
            else
            {
                if (s.empty())
                    return false;
                char c = s.top();
                s.pop();
                if ((str[i] == '}' && c == '{') || (str[i] == ')' && c == '(') || (str[i] == ']' && c == '['))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return s.empty();
    }
};
int main()
{
    Stack s;
    string str = "()[]{}";
    cout << s.validParenthesis(str);

    return 0;
}