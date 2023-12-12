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
    bool ans = true;
    bool isBalanced(Node *root)
    {
        int x = checkBalanced(root);
        return ans;
    }
    int checkBalanced(Node *root)
    {
        if (root == NULL)
            return 0;

        int lh = checkBalanced(root->left);
        int rh = checkBalanced(root->right);

        int gap = abs(rh - lh);
        if (gap > 1)
        {
            ans = false;
        }

        return max(lh, rh) + 1;
    }
};
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->right->left->left = new Node(9);
    root->right->left->right = new Node(9);

    root->right->left->right->right = new Node(9);

    Solution s;
    cout << "Max Depth of the tree is " << s.checkBalanced(root) << endl;
    cout << "isBalanced: " << s.isBalanced(root);
}