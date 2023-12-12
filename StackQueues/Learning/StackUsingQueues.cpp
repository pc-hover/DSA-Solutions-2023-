#include <bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> Q;

public:
    void push(int x)
    {
        Q.push(x);
        for (int i = 0; i < Q.size() - 1; i++)
        {
            Q.push(Q.front());
            Q.pop();
        }
    }
    void pop()
    {
        Q.pop();
    }
    int getTop()
    {
        return Q.front();
    }
};
int main()
{
    Stack s;
    s.push(20);
    s.push(40);
    s.push(20);
    cout << s.getTop();
    s.push(60);
    s.push(35);
    cout << s.getTop();
}