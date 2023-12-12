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
    int maxdepth(Node *root)
    {
        if (root == NULL)
            return 0;

        int lh = maxdepth(root->left);
        int rh = maxdepth(root->right);

        return 1 + max(lh, rh);
    }
};
int main()
{
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->right->left = new Node(4);
    root->right->right = new Node(6);

    root->right->left->left = new Node(5);

    Solution s;
    cout << "Max Depth of the tree is " << s.maxdepth(root);
}