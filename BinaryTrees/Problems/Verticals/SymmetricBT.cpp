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
    bool isSymmetric(Node *left, Node *right)
    {
        if (!right || !left)
            return right == left;

        if (left->data != right->data)
        {
            return false;
        }
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    bool checkSymmetry(Node *root)
    {
        return root == NULL || isSymmetric(root->left, root->right);
    }
};
int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->left->right = new Node(3);

    root->right = new Node(2);
    root->right->right = new Node(3);

    Solution s;
    cout << "Symmetric Binary Tree : " << s.checkSymmetry(root);
    return 0;
}