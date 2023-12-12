#include <bits/stdc++.h>
using namespace std;
class Stack
{

    int size;
    int *arr; // CREATING DYNAMIC ARRAY pointer pointing to array block
    int top;

public:
    Stack()
    {
        size = 1000;
        arr = new int[size]; // dynamic array
        top = -1;
    }
    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
    void push(int x)
    {
        if (top == size)
        {
            cout << "FULL";
            return;
        }
        arr[++top] = x;
    }
    int getTop()
    {
        return arr[top];
    }
    int pop()
    {
        int x = arr[top];
        top--;
        return x;
    }
    bool isEmpty()
    {
        return top == -1;
    }
};
int main()
{
    Stack s;
    s.push(6);
    s.push(5);
    s.push(9);
    s.push(8);
    s.print();
    s.pop();
    cout << s.getTop() << endl;
    s.print();
    s.push(3);
    s.push(5);
    cout << s.getTop();
    //     s.pop();
    //     s.push(2);
    //     s.push(76);
    //    s.print();
}