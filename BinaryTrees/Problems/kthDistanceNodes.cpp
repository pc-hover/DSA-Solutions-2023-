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
    void getParentMarked(Node *root, unordered_map<Node *, Node *> &markp)
    {
        if (!root)
            return;
        queue<Node *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            Node *node = Q.front();
            Q.pop();
            if (node->left)
            {
                markp[node->left] = node;
                Q.push(node->left);
            }
            if (node->right)
            {
                markp[node->right] = node;
                Q.push(node->right);
            }
        }
    }

public:
    vector<int> kthDistanceNodes(Node *root, Node *target, int k)
    {
        unordered_map<Node *, Node *> markp;
        getParentMarked(root, markp);

        queue<Node *> Q;
        unordered_map<Node *, bool> visited;
        int dis = 0;
        Q.push(target);
        visited[target] = true;
        while (!Q.empty())
        {
            int size = Q.size();
            if (dis == k)
                break;
            dis++;
            for (int i = 0; i < size; i++)
            {
                Node *current = Q.front();
                Q.pop();

                if (current->left && !visited[current->left])
                {
                    Q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right])
                {
                    Q.push(current->right);
                    visited[current->right] = true;
                }
                if (markp[current] && !visited[markp[current]])
                {
                    Q.push(markp[current]);
                    visited[markp[current]] = true;
                }
            }
        }
        vector<int> ans;
        while (!Q.empty())
        {
            ans.push_back(Q.front()->data);
            Q.pop();
        }
        return ans;
    }
};
int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->left->left = new Node(6);
    root->left->right = new Node(2);

    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    root->right = new Node(1);
    root->right->right = new Node(8);
    root->right->left = new Node(0);

    Solution s;
    Node *target = root->left;
    int k = 2;
    vector<int> ans = s.kthDistanceNodes(root, target, k);

    for (auto it : ans)
    {
        cout << " " << it;
    }

    return 0;
}