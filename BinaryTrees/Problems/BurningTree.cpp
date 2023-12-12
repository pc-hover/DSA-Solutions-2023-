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
        queue<Node *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            int n = Q.size();

            Node *node = Q.front();
            Q.pop();

            if (node->left)
            {
                Q.push(node->left);
                markp[node->left] = node;
            }
            if (node->right)
            {
                Q.push(node->right);
                markp[node->right] = node;
            }
        }
    }

public:
    int timeToBurnTree(Node *root, Node *target)
    {
        unordered_map<Node *, Node *> pmp;
        if (!root)
            return 0;
        getParentMarked(root, pmp);
        int time = 0;
        queue<Node *> Q;
        unordered_map<Node *, int> visit;
        Q.push(target);
        visit[target] = 1;
        while (!Q.empty())
        {
            int size = Q.size();
            int fl = 0;
            for (int i = 0; i < size; i++)
            {
                Node *node = Q.front();

                Q.pop();

                if (!visit[pmp[node]] && pmp[node])
                {
                    fl = 1;
                    Q.push(pmp[node]);
                    visit[pmp[node]] = 1;
                }
                if (!visit[node->left] && node->left)
                {
                    fl = 1;
                    Q.push(node->left);
                    visit[node->left] = 1;
                }
                if (!visit[node->right] && node->right)
                {
                    fl = 1;
                    Q.push(node->right);
                    visit[node->right] = 1;
                }
            }
            if (fl)
            {
                ++time;
            }
        }
        return time;
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
    int ans = s.timeToBurnTree(root, target);
    cout << ans;

    return 0;
}