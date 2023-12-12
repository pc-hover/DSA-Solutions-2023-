#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
    stack<int> input, output;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        if (output.empty())
        {
            while (input.size())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int x = output.top();
        output.pop();
        return x;
    }

    int peek()
    {
        if (output.empty())
        {
            while (input.size())
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty()
    {
        if (output.empty())
        {
            while (input.size())
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.empty();
    }
};
int main()
{
    MyQueue Q;
    Q.push(6);
    Q.push(5);
    Q.push(9);
    Q.push(8);

    Q.pop();
    cout << Q.peek() << endl;

    Q.push(3);
    Q.push(5);
    cout << Q.peek();
    //     Q.pop();
    //     Q.push(2);
    //     Q.push(76);
    //
}