#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->right = NULL;
        this->left = NULL;
    }
    Node()
    {
        this->data = 0;
        this->right = NULL;
        this->left = NULL;
    }
};
class Solution
{
public:
    bool checkIdentical(Node *p, Node *q)
    {
        if (p == NULL || q == NULL)
            return p == q;

        // 1. values must be equal
        // 2. sending left subtree recursive
        // 3. sending right subtree recursive

        return p->data == q->data && checkIdentical(p->left, q->left) && checkIdentical(p->right, q->right);
    }
};
int main()
{
    struct Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    root1->right->left = new Node(4);
    root1->right->right = new Node(6);

    root1->right->left->left = new Node(5);

    struct Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    root2->right->left = new Node(4);
    root2->right->right = new Node(6);

    root2->right->left->left = new Node(5);

    Solution s;
    cout << "R these 2 equal: " << s.checkIdentical(root1, root2);
}