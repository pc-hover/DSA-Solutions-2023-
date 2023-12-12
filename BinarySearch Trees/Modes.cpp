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
    void finddups(Node *root, vector<int> &inorder)
    {
        if (!root)
            return;

        finddups(root->left, inorder);
        inorder.push_back(root->data);
        finddups(root->right, inorder);
    }
    vector<int> Modes(Node *root)
    {
        vector<int> ans;
        if (!root)
        {
            return ans;
        }
        vector<int> inorder;
        finddups(root, inorder);
        unordered_map<int, int> mp;
        int maxi = INT_MIN;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]]++;
            maxi = max(maxi, mp[inorder[i]]);
        }
        for (auto it : mp)
        {
            if (it.second == maxi)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(5);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(5);

    root->right = new Node(7);
    root->right->right = new Node(10);
    root->right->right->left = new Node(9);
    root->right->right->left->right = new Node(11);
    root->right->right->left->left = new Node(10);

    Solution s;
    vector<int> ans = s.Modes(root);

    for (auto it : ans)
    {
        cout << " " << it;
    }

    return 0;
}