
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
    TreeNode(int item)
    {
        left = NULL;
        right = NULL;
        val = item;
    }
};
class Solution
{
public:
    TreeNode *func(vector<int> arr, int &i, int bound) //************index by reference
    {
        // edge cases
        //  1. a[i] out of bound
        //  2. array has finished

        if (i == arr.size() || arr[i] > bound)
            return NULL;

        TreeNode *root = new TreeNode(arr[i++]);

        root->left = func(arr, i, root->val);
        root->right = func(arr, i, bound);

        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return func(preorder, i, INT_MAX);
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
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution s;
    TreeNode *root = s.bstFromPreorder(preorder);
    s.preOrder(root);

    return 0;
}
