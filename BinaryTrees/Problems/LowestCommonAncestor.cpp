#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        this->left = NULL;
        this->right = NULL;
        this->val = 0;
    }
    TreeNode(int val)
    {
        this->left = NULL;
        this->right = NULL;
        this->val = val;
    }
};
class Solution
{
public:
    TreeNode *findLCA(TreeNode *root, TreeNode *x, TreeNode *y)
    {
        if (root == NULL || root == x || root == y)
            return root;

        TreeNode *lhs = findLCA(root->left, x, y);
        TreeNode *rhs = findLCA(root->right, x, y);

        if (lhs == NULL)
        {
            return rhs;
        }
        else if (rhs == NULL)

        {
            return lhs;
        }
        else
        {
            return root; // both lhs and rhs are not null
        }
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    //[3,5,1,6,2,0,8,null,null,7,4]
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    root->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    root->right->left = new TreeNode(8);

    Solution s;

    TreeNode *ans = s.findLCA(root, root->left->left, root->left->right->right); // 4,7
    cout << "LCA is " << ans->val;

    return 0;
}