
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

        traversal(root->left);
        traversal(root->right);
        cout << " " << root->data;
    }

    Node *func(vector<int> &inorder, int a, int b, vector<int> &postOrder, int x, int y, map<int, int> &mark)

    {
        if (a > b || x > y)
        {
            return NULL;
        }
        Node *root = new Node(postOrder[y]);

        int inRoot = mark[postOrder[y]];
        int numsLeft = inRoot - a; // number of elements on the left of the root in inorde

        root->left = func(inorder, a, inRoot - 1, postOrder, x, x + numsLeft - 1, mark);

        root->right = func(inorder, inRoot + 1, b, postOrder, x + numsLeft, y - 1, mark);

        return root;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &postOrder)
    {
        map<int, int> mark;
        for (int i = 0; i < inorder.size(); i++)
        {
            mark[inorder[i]] = i;
        }
        return func(inorder, 0, inorder.size() - 1, postOrder, 0, postOrder.size() - 1, mark);
    }
};
int main()
{
    Solution s;
    vector<int> postOrder = {9, 15, 7, 20, 3};
    vector<int> inOrder = {9, 3, 15, 20, 7};
    Node *root = s.buildTree(inOrder, postOrder);
    s.traversal(root);
}

// Node *func(int &index, vector<int> &postOrder, int start, int end, unordered_map<int, int> &mark)
// {
//     if (start >= end)
//         return NULL;

//     int inRoot = mark[postOrder[index]];
//     if (inRoot < start || inRoot > end)
//         return NULL;
//     Node *root = new Node(postOrder[index]);
//     index--;
//     root->left = func(index, postOrder, start, inRoot - 1, mark);
//     root->right = func(index, postOrder, inRoot, index, mark);

//     return root;
// }

// Node *buildTree(vector<int> &inOrder, vector<int> &postOrder)
// {
//     unordered_map<int, int> mark;
//     int n = inOrder.size() - 1;
//     for (int i = 0; i < inOrder.size(); i++)
//     {
//         mark[inOrder[i]] = i;
//     }
//     return func(n, postOrder, 0, n, mark);

//     // When you pass a pointer by a non-const reference, you are telling the compiler that you are going to modify that pointer's value. Your code does not do that, but the compiler thinks that it does, or plans to do it in the future.
// }