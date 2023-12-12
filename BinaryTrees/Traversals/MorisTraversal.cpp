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

vector<int> inOrder(TreeNode *root) // INORDER TRAVERSAL
{
    vector<int> inorder;
    if (!root)
    {
        return inorder;
    }
    while (root != NULL)
    {
        if (root->left == NULL)
        {
            inorder.push_back(root->val);
            root = root->right;
        }

        else
        {
            TreeNode *temp = root->left;
            while (temp->right != NULL && temp->right != root)
            {
                temp = temp->right;
            }
            if (temp->right == NULL) // CREATE THREAD
            {
                temp->right = root;
                root = root->left;
            }
            if (temp->right == root) // REMOVE THREAD
            {
                temp->right = NULL;
                inorder.push_back(root->val);
                root = root->right;
            }
        }
    }
    return inorder;
}
vector<int> preOrder(TreeNode *root) // INORDER TRAVERSAL
{
    vector<int> preorder;
    if (!root)
    {
        return preorder;
    }
    while (root != NULL)
    {
        if (root->left == NULL)
        {
            preorder.push_back(root->val);
            root = root->right;
        }

        else
        {
            TreeNode *temp = root->left;
            while (temp->right != NULL && temp->right != root)
            {
                temp = temp->right;
            }
            if (temp->right == NULL) // CREATE THREAD
            {
                temp->right = root;

                preorder.push_back(root->val); //!!

                root = root->left;
            }
            if (temp->right == root) // REMOVE THREAD
            {
                temp->right = NULL;

                root = root->right;
            }
        }
    }
    return preorder;
}

int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    vector<int> ans = inOrder(root);
    vector<int> ans2 = preOrder(root);
    cout << "Inorder  : ";
    for (const auto &column : ans)
    {
        cout << " " << column;
    }
    cout << endl;
    cout << "Preorder : ";
    for (const auto &column : ans2)
    {
        cout << " " << column;
    }
}