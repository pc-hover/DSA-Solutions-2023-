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
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        map<int, int> mp;           //(v->node)
        queue<pair<Node *, int>> Q; //(node,v)

        Q.push({root, 0});
        while (!Q.empty())
        {
            Node *node = Q.front().first;
            int v = Q.front().second;
            mp[v] = node->data;
            Q.pop();
            if (node->left)
                Q.push({node->left, v - 1});
            if (node->right)
                Q.push({node->right, v + 1});
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
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    root->right = new Node(3);
    root->right->right = new Node(7);
    root->right->left = new Node(6);

    Solution s;
    vector<int> ans = s.bottomView(root);
    for (auto it : ans)
    {
        cout << " " << it;
    }

    return 0;
}