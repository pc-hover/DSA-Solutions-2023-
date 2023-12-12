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
    int findHeightLeft(Node *root)
    {
        int ht = 0;
        while (root)
        {
            root = root->left;
            ht++;
        }
        return ht;
    }
    int findHeightRight(Node *root)
    {
        int ht = 0;
        while (root)
        {
            root = root->right;
            ht++;
        }
        return ht;
    }

public:
    int countNodes(Node *root)
    {
        int count = 0;
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        if (lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->left->left = new Node(6);
    root->left->left->right = new Node(2);

    root->right = new Node(1);
    root->right->right = new Node(8);
    root->right->left = new Node(0);

    Solution s;
    Node *target = root->left;
    int ans = s.countNodes(root);
    cout << ans;

    return 0;
}