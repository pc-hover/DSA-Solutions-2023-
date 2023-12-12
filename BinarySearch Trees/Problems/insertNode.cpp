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
    Node(int item)
    {
        left = NULL;
        right = NULL;
        val = item;
    }
};
class Solution
{
public:
    // Tim Complexity -> O(log base 2 (n)) {height of the binary tree}

    Node *insertIntoBST(Node *&root, int item)
    {
        Node *node = root;
        while (node)
        {

            if (node->val > item)
            {
                if (node->left)
                {
                    node = node->left;
                }
                else
                {
                    node->left = new Node(item);
                    break;
                }
            }

            else if (node->val <= item)
            {
                if (node->right)
                {
                    node = node->right;
                }
                else
                {
                    node->right = new Node(item);
                    break;
                }
            }
        }
        return root;
    }
    void inorder(Node *root)
    {
        if (!root)
            return;

        inorder(root->left);
        cout << " " << root->val;
        inorder(root->right);
    }
};
int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution s;
    s.inorder(root);
    s.insertIntoBST(root, 5);
    cout << endl;
    s.inorder(root);
    return 0;
}