#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode()
    {
        left = NULL;
        right = NULL;
        val = 0;
    }
    TreeNode(int data)
    {
        left = NULL;
        right = NULL;
        val = data;
    }
};
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left != NULL)
            {
                TreeNode *temp = cur->left;
                while (temp->right)
                {
                    temp = temp->right;
                }
                temp->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL; //!!!!!!!
            }
            cur = cur->right;
        }
    }
    // using RECURSION
    TreeNode *prev = NULL;
    void flatten2(TreeNode *root)
    {
        if (!root)
            return;
        flatten2(root->left);
        flatten2(root->right);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
    void preOrder(TreeNode *root)
    {
        if (!root)
            return;

        cout << " " << root->val;
        preOrder(root->left);
        preOrder(root->right);
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution s;
    s.preOrder(root);
    cout << endl;
    s.flatten2(root);
    while (!root)
    {
        cout << " " << root->val;
        root = root->right;
    }

    return 0;
}