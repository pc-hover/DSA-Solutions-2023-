#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *left;
    Node *right;
    int val;
    Node()
    {
        left = NULL;
        right = NULL;
        val = 0;
    }
    Node(int data)
    {
        left = NULL;
        right = NULL;
        val = data;
    }
};
class Solution
{
public:
    Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
    {

        if (!root)
            return root;

        while (root)
        {
            if (root->val > p->val && root->val > q->val)
            {
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val)
            {
                root = root->left;
            }
            else
            {
                return root;
            }
        }
        return root;
    }
};
int main()
{
    struct Node *root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);
    root->right->right = new Node(9);
    root->right->left = new Node(7);

    Solution s;
    cout << s.lowestCommonAncestor(root, root->right, root->left->right->right)->val;
    return 0;
}