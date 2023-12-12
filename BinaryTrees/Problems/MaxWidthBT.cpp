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
    int maxWidth(TreeNode *root)
    {
        if (!root)
            return 0;

        int ans = 0;
        queue<pair<TreeNode *, int>> Q;
        Q.push({root, 0});
        while (!Q.empty())
        {
            int size = Q.size();
            int xmin = Q.front().second; // first element from the left in one level
            int first, last;             // max width calc
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = Q.front().first;
                int index = Q.front().second - xmin; // preparing
                Q.pop();
                if (i == 0)
                {
                    first = index;
                }
                if (i == size - 1)
                {
                    last = index;
                }
                if (node->left)
                {
                    Q.push({node->left, 2 * (index) + 1});
                }

                if (node->right)
                {
                    Q.push({node->right, 2 * (index) + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);

    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);

    Solution s;

    int ans = s.maxWidth(root);
    cout << "MAX Width is " << ans;

    return 0;
}