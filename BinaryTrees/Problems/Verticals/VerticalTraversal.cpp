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
    vector<vector<int>> VerticalTraveral(Node *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        map<int, map<int, multiset<int>>> nodes;  // x-->y->node
        queue<pair<Node *, pair<int, int>>> todo; // node,(x,y)

        todo.push({root, {0, 0}});
        while (!todo.empty())
        {
            auto p = todo.front();
            todo.pop();
            Node *node = p.first;
            int x = p.second.first;  // vertical
            int y = p.second.second; // level

            nodes[x][y].insert(node->data);
            if (node->left)
                todo.push({node->left, {x - 1, y + 1}});
            if (node->right)
                todo.push({node->right, {x + 1, y + 1}});
        }
        // Now extracting data from map and putting it in ans
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end()); // column ke end mein add karenge begin() -> end() of q.second/multiset
            }
            ans.push_back(col);
        }
        return ans;
    }
    // using INORDER TRAVERSAL
    void VerticalTraveral2(Node *node, int x, int y, map<int, map<int, multiset<int>>> &mp)
    {

        if (!node)
            return;

        mp[x][y].insert(node->data);
        VerticalTraveral2(node->left, x - 1, y + 1, mp);
        VerticalTraveral2(node->right, x + 1, y + 1, mp);
    }
    vector<vector<int>> Solve(Node *root)
    {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes; // x-->y->node
        VerticalTraveral2(root, 0, 0, nodes);
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
int main()
{
    Node *root = new Node(1);

    root->left = new Node(3);
    root->left->right = new Node(10);
    root->left->left = new Node(4);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);

    root->right = new Node(2);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution s;
    vector<vector<int>> ans = s.VerticalTraveral(root);

    for (auto it : ans)
    {
        for (auto it2 : it)
        {
            cout << " " << it2;
        }
    }

    return 0;
}