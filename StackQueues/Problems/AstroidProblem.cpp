#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &ast)
{
    stack<int> stack;
    for (int i = 0; i < ast.size(); i++)
    {
        int flag = 1;
        while (!stack.empty() && (stack.top() > 0 && ast[i] < 0))
        {
            if (abs(stack.top()) < abs(ast[i]))
            {
                stack.pop();
                continue;
            }
            else if (abs(stack.top()) == abs(ast[i]))

            {
                stack.pop();
            }
            flag = 0;
            break;
        }
        if (flag)
        {
            stack.push(ast[i]);
        }
    }
    vector<int> ans(stack.size());
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        ans[i] = stack.top();
        stack.pop();
    }

    return ans;
}
int main()
{
    vector<int> nums = {5, 10, -5};
    vector<int> ans = asteroidCollision(nums);
    for (auto it : ans)
    {
        cout << " " << it;
    }
    return 0;
}