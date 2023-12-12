#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *left;
    Node *right;
    int val;
    Node()
    {
        left = NULL;
        right = NULL;
        val = 0;
    }
    Node(int data)
    {
        left = NULL;
        right = NULL;
        val = data;
    }
};
class Solution
{
public:
    bool func(Node *root, int lb, int ub)
    {
        if (root == NULL)
            return true;

        if (root->val < lb || root->val > ub)
            return false;

        return func(root->left, lb, root->val) && func(root->right, root->val, ub);
    }
    bool checkValidBst(Node *root)
    {
        if (!root)
            return false;
        int lb = INT_MIN;
        int ub = INT_MAX;
        return func(root, lb, ub);
    }
};
int main()
{
    struct Node *root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);
    root->right->right = new Node(9);
    root->right->left = new Node(7);

    Solution s;
    cout << s.checkValidBst(root) << endl;
    return 0;
}