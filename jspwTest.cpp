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
public:
    bool isLeaf(Node *node)
    {
        return !node->left && !node->right;
    }
    // 1.to traverse left half excluding leaf nodes
    void addLeft(Node *root, vector<int> &ans)
    {
        Node *cur = root->left;
        while (cur)
        {
            if (!isLeaf(cur))
                ans.push_back(cur->data);

            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }
    // 2.to traverse right half excluding leaf nodes and in reverse order
    void addRight(Node *root, vector<int> &ans)
    {
        Node *cur = root->right;
        stack<int> temp;

        while (cur)
        {
            if (!isLeaf(cur))
                temp.push(cur->data);

            if (cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }
        while (!temp.empty())
        {
            ans.push_back(temp.top());
            temp.pop();
        }
    }
    // 3.store leaf nodes for this we will simply traverse the tree using inorder poster or preorder any of these methods
    void addLeafs(Node *root, vector<int> &ans)
    {

        if (root->left)
            addLeafs(root->left, ans);
        if (isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }

        if (root->right)
            addLeafs(root->right, ans);
    }

    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        ans.push_back(root->data);
        addLeft(root, ans);
        addLeafs(root, ans);
        addRight(root, ans);

        return ans;
    }
};
int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->left->right = new Node(11);
    root->right->right->left->left = new Node(10);

    Solution s;
    vector<int> ans = s.boundaryTraversal(root);

    for (auto it : ans)
    {
        cout << " " << it;
    }

    return 0;
}