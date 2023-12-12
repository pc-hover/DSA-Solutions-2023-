#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *left;
    Node *right;
    int data;
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
    // Tim Complexity -> O(log base 2 (n)) {height of the binary tree}
    // Node *searchBST(Node *root, int x)
    // {
        
    // }
    // striver
    Node *searchBST2(Node *root, int val)
    {
        while (root && root->data != val) // bc loop chl rha haiii
        {
            root = root->data > val ? root->left : root->right;
        }
        return root;
    }
};
int main()
{
    struct Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    Solution s;
    Node *ans = s.searchBST2(root, 130);
    if (!ans)
        cout << "Element Not Found";
    else
    {
        cout << ans->data;
    }

    return 0;
}