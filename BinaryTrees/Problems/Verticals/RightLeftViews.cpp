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
    void func(Node *root, int level, vector<int> &ds)
    {
        if (!root)
            return;

        if (level == ds.size())
        {
            ds.push_back(root->data);
        }
        func(root->right, level + 1, ds);
        func(root->left, level + 1, ds);
    }
    vector<int> rightView(Node *root)
    {

        vector<int> ans;
        func(root, 0, ans);
        return ans;
    }
};
int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->left->right->left = new Node(6);

    root->right = new Node(3);
    root->right->right = new Node(7);

    Solution s;
    vector<int> ans = s.rightView(root);
    for (auto it : ans)
    {
        cout << " " << it;
    }

    return 0;
}