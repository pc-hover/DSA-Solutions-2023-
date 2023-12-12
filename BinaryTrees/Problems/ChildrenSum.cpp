#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node()
    {
        left = NULL;
        right = NULL;
        data = 0;
    }
    Node(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};
class Solution
{
public:
    void preorder(Node *root)
    {
        if (!root)
            return;
        cout << " " << root->data;

        preorder(root->left);
        preorder(root->right);
    }
    void changeTree(Node *root)
    {
        if (!root)
            return;

        int child = 0;

        if (root->left)
            child += root->left->data;
        if (root->right)
            child += root->right->data;

        if (child >= root->data)
            root->data = child;
        else
        {
            if (root->left)
                root->left->data = root->data;
            if (root->right)
                root->right->data = root->data;
        }

        changeTree(root->left);
        changeTree(root->right);

        // backtrack
        int total = 0;
        if (root->left)
            total += root->left->data;
        if (root->right)
            total += root->right->data;

        if (root->left || root->right)
            root->data = total;
    }
};
int main()
{
    Node *root = new Node(40);

    root->left = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(5);

    root->right = new Node(20);
    root->right->right = new Node(40);
    root->right->left = new Node(30);

    Solution s;
    s.preorder(root);
    s.changeTree(root);
    cout << endl;
    s.preorder(root);

    return 0;
}