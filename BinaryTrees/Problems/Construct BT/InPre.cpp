// ISSUE -> MEMORY EXCEDED RECURSION TREE USES MASSIVE MEMORY
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
    void traversal(Node *root)
    {
        if (!root)
            return;

        cout << " " << root->data;
        traversal(root->left);
        traversal(root->right);
    }
    // memory exceeded
    Node *func(int in_start, int in_end, vector<int> &inorder, int pre_start, int pre_end, vector<int> &preorder, map<int, int> hash)

    {
        if (in_start > in_end || pre_start > pre_end)
        {
            return NULL;
        }
        Node *root = new Node(preorder[pre_start]);

        int inRoot = hash[root->data];
        int numsLeft = inRoot - in_start; // number of elements on the left of the root in inorde

        root->left = func(in_start, inRoot - 1, inorder, pre_start + 1, pre_start + numsLeft, preorder, hash);
        root->right = func(inRoot + 1, in_end, inorder, pre_start + numsLeft + 1, pre_end, preorder, hash);

        return root;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &preorder)
    {
        map<int, int> hash;
        for (int i = 0; i < inorder.size(); i++)
        {
            hash[inorder[i]] = i;
        }
        return func(0, inorder.size() - 1, inorder, 0, preorder.size() - 1, preorder, hash);
    }
    Node *f(int &i, int l, int h, vector<int> &pre, unordered_map<int, int> &mp)
    {
        if (l > h)
            return NULL;
        int id = mp[pre[i]];
        if (id < l || id > h)
            return NULL;
        Node *root = new Node(pre[i]);
        i++;
        root->left = f(i, l, id - 1, pre, mp);
        root->right = f(i, id + 1, h, pre, mp);
        return root;
    }
    Node *buildTree2(vector<int> &in, vector<int> &pre)
    {
        int n = pre.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[in[i]] = i;
        int i = 0;
        return f(i, 0, n - 1, pre, mp);
    }
};
int main()
{
    Solution s;
    vector<int> preorder = {10, 20, 40, 50, 30, 60};
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    Node *root = s.buildTree(inorder, preorder);
    Node *root2 = s.buildTree2(inorder, preorder);
    s.traversal(root2);
}