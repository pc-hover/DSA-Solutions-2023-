#include <bits/stdc++.h>
using namespace std;

class Queue
{

    int front;
    int rear;
    int size;
    int cnt;
    int *arr;

public:
    Queue()
    {
        front = -1;
        rear = -1;
        arr = new int(5);
    }
    Queue(int value)
    {
        this->size = value;
        front = -1;
        rear = -1;
        arr = new int(size);
        this->cnt = 0;
    }

    void print() // check it out
    {
        int n = cnt;
        for (int i = front; n--; i++) // rear kabhi peeche nhi ayga we eill keep on increasing it! to access the before elements we will use rear%size
        {
            cout << arr[i % size] << " ";
        }
        cout << endl;
    }
    void push(int x)
    {
        if (cnt == size)
        {
            cout << "full";
            exit(1);
        }
        if (rear == -1)
        {
            rear = 0;
            front = 0;
        }
        else
        {
            rear = rear + 1;
        }
        arr[rear % size] = x;

        cnt = cnt + 1;
    }
    void pop()
    {
        if (cnt == 0)
        {
            cout << "Empty";
            exit(1);
        }
        arr[front % size] == -1;
        front++;
        cnt--;
    }
    int getTop()
    {
        return arr[front % size];
    }
};
int main()
{
    Queue s(5);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.print();
    s.pop();
    s.pop();
    s.print();
    cout << s.getTop();
}