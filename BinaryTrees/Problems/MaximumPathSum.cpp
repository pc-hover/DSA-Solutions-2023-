// Hard Problem

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
    int MaxPathSum(Node *root)
    {
        int maxi = INT_MIN;
        PathSum(root, maxi);
        return maxi;
    }
    int PathSum(Node *node, int &maxi)
    {
        if (node == NULL)
            return 0;

        int lh = PathSum(node->left, maxi);
        int rh = PathSum(node->right, maxi);

        maxi = max(lh + rh + node->data, maxi);

        return max(lh, rh) + node->data;
    }
};
int main()
{
    struct Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);

    root->right->left = new Node(15);
    root->right->right = new Node(7);

    Solution s;
    int maxi = 0;
    cout << "Maximum Path Sum = " << s.MaxPathSum(root);

    return 0;
}