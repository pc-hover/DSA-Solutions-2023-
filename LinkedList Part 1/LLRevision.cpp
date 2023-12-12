#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int var)
    {
        this->data = var;
        this->next = NULL;
    }
};

void insertAthead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void insertAtMiddle(Node *&head, Node *&tail, int data, int pos)
{
    Node *temp = head;
    int ct = 1;
    if (pos == 1)
    {
        insertAthead(head, data);
        return;
    }
    while (ct != pos - 1)
    {
        temp = temp->next;
        ct++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    Node *p = new Node(data);
    p->next = temp->next;
    temp->next = p;
}
void deleteNode(Node *&head, Node *&tail, int pos)
{

    if (pos <= 0)
    {
        cout << "invalid input";
        return;
    }
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete (temp);
        return;
    }
    int ct = 1;
    Node *temp = head;
    Node *curr = head->next;
    while (ct != pos - 1)
    {
        temp = temp->next;
        curr = curr->next;
        ct++;
    }
    if (curr->next == NULL)
    {
        tail = temp;
    }
    temp->next = curr->next;
    delete (curr);
    return;
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{

    Node *node1 = new Node(20);
    Node *head = node1;
    Node *tail = node1;

    insertAthead(head, 30);
    insertAthead(head, 40);
    display(head);

    insertAtTail(tail, 10);
    display(head);

    insertAtMiddle(head, tail, 12, 1);
    insertAtMiddle(head, tail, 90, 6);
    insertAtMiddle(head, tail, 62, 2);
    display(head);

    deleteNode(head, tail, 1);
    display(head);
    deleteNode(head, tail, 5);
    display(head);
    deleteNode(head, tail, 5);
    display(head);
    deleteNode(head, tail, 2);
    display(head);

    cout << "(" << head->data << "," << tail->data << ")";

    return 0;
}