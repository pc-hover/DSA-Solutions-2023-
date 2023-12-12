#include <bits/stdc++.h>
using namespace std;

// TC -> O(N)
// SC -> O(1)
class LRUCache
{
public:
    class Node
    {
    public:
        Node *prev;
        Node *next;
        int key;
        int value;

        Node(int xkey, int xvalue)
        {
            this->key = xkey;
            this->value = xvalue;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap; // stores current capacity
    unordered_map<int, Node *> mp;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(Node *xnode)
    {
        Node *temp = head->next;
        xnode->next = temp;
        xnode->prev = head;
        head->next = xnode;
        temp->prev = xnode;
    }
    void deletenode(Node *xnode)
    {
        Node *temp = xnode->prev;
        Node *temp2 = xnode->next;
        temp->next = temp2;
        temp2->prev = temp;
    }
    int get(int xkey)
    {
        if (mp.find(xkey) != mp.end())
        {
            Node *resnode = mp[xkey]; // took the address
            int res = resnode->value; // took its value

            mp.erase(xkey); // killed it
            deletenode(resnode);
            addnode(resnode); //!!!!!!!!!!!!!!!!!!!!!!!!!
            mp[xkey] = head->next;
            return res;
        }
        return -1;
    }

    void put(int xkey, int xvalue)
    {
        if (mp.find(xkey) != mp.end())
        {
            Node *existingNode = mp[xkey];
            mp.erase(xkey); // poora hash element hatega
            deletenode(existingNode);
        }
        if (cap == mp.size())
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new Node(xkey, xvalue));
        mp[xkey] = head->next;
    }
};
int main()
{
    LRUCache CACHE1(3);

    CACHE1.put(1, 10);

    CACHE1.put(3, 15);

    CACHE1.put(2, 12);

    cout << CACHE1.get(3);

    CACHE1.put(4, 25);
}