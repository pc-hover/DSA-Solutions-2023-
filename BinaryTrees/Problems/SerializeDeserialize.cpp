#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
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
    // TC->O(N)
    // SC->O(N)
    string serialize(TreeNode *root)
    {
        string str;
        if (!root)
            return str;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            TreeNode *node = Q.front();
            Q.pop();

            if (node == NULL)
                str.append("#,");
            if (node != NULL)
                str.append(to_string(node->val) + ",");

            if (node != NULL) // null node ke left or right nhi lenge
            {
                Q.push(node->left);
                Q.push(node->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            TreeNode *node = Q.front();
            Q.pop();

            getline(s, str, ',');
            if (str == "#")
            {
                node->left = NULL;
            }
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                Q.push(leftNode);
            }

            getline(s, str, ',');
            if (str == "#")
                node->right = NULL;
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                Q.push(rightNode);
            }
        }
        return root;
    }
    void preOrder(TreeNode *root)
    {
        if (!root)
            return;

        cout << " " << root->val;

        if (root->left)
            preOrder(root->left);
        if (root->right)
            preOrder(root->right);
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->right = new TreeNode(4);

    root->right = new TreeNode(1);

    Solution s;
    string ans = s.serialize(root);
    cout << ans << endl;
    TreeNode *rootAns = s.deserialize(ans);
    s.preOrder(rootAns);
    cout << endl;
    s.preOrder(root);

    return 0;
}