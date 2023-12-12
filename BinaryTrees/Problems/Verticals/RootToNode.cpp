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
    // recursive function
    bool findPath(Node *root, vector<int> &ans, int x)
    {
        if (!root)
            return false;

        ans.push_back(root->data);

        if (root->data == x)
            return true;

        if (findPath(root->left, ans, x) || findPath(root->right, ans, x))
            return true;

        ans.pop_back();
        return false;
    }
    vector<int> rootToNode(Node *root, int v)
    {
        vector<int> ans;
        if (!root)
            return ans;

        findPath(root, ans, v);
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
    root->left->right->right = new Node(7);

    root->right = new Node(3);
    root->right->right = new Node(7);
    root->right->left = new Node(6);

    Solution s;
    vector<int> ans = s.rootToNode(root, 7);
    for (auto it : ans)
    {
        cout << " " << it;
    }

    return 0;
}