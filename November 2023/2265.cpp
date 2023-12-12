#include <iostream>
#include <unordered_map>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        int count = 0;
        dfs(root, count);
        return count;
    }

    std::pair<int, int> dfs(TreeNode *node, int &count)
    {
        if (!node)
        {
            return {0, 0};
        }

        auto left = dfs(node->left, count);
        auto right = dfs(node->right, count);

        int totalSum = left.first + right.first + node->val;
        int totalCount = left.second + right.second + 1;

        if (node->val * totalCount == totalSum)
        {
            count++;
        }

        return {totalSum, totalCount};
    }
};

int main()
{
    // Example usage
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(6);

    Solution solution;
    std::cout << "Output: " << solution.countNodes(root) << std::endl; // Output: 5

    // Don't forget to free the allocated memory to prevent memory leaks
    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
