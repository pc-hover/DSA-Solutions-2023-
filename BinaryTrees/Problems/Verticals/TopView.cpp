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
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        map<int, int> mp;
        queue<pair<Node *, int>> Q;

        Q.push({root, 0});
        while (!Q.empty())
        {
            Node *node = Q.front().first;
            int v = Q.front().second;

            if (mp.find(v) == mp.end()) // very imp ***********
            {
                mp[v] = node->data;
            }
            Q.pop();
            if (node->left)
            {
                Q.push({node->left, v - 1});
            }
            if (node->right)
            {
                Q.push({node->right, v + 1});
            }
        }
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
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
    vector<int> ans = s.topView(root);
    for (auto it : ans)
    {
        cout << " " << it;
    }

    return 0;
}