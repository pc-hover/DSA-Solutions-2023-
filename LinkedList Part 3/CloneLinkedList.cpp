#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int _val)
    {
        data = _val;
        next = NULL;
        random = NULL;
    }
};
Node *cloneLL(Node *head)
{
    // Add copy nodes
    Node *itor = head;
    Node *front = head;
    while (itor != NULL)
    {
        front = itor->next;
        Node *copyNode = new Node(itor->data);
        itor->next = copyNode;
        copyNode->next = front;
        itor = front;
    }
    // Connect random links
    itor = head;
    while (itor != NULL)
    {
        if (itor->random != NULL)
        {
            itor->next->random = itor->random->next;
            itor = itor->next->next;
        }
    }
    // Remove original LL
    Node *dummyNode = new Node(0);
    Node *temp = dummyNode;
    itor = head;
    while (itor != NULL)
    {
        front = itor->next->next;
        temp->next = itor->next;
        itor->next = front;
        temp = temp->next;
        itor = front;
    }

    return dummyNode->next;
}