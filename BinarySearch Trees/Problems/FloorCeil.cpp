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

    Node *Floor(Node *root, int val)
    {
        Node *ans;
        while (root)
        {
            if (root->data == val)
            {
                return root;
            }
            else if (root->data < val)
            {
                ans = root;
                root = root->right;
            }
            else
                root = root->left;
        }
        return ans;
    }
    Node *ceil(Node *root, int val)

    {
        Node *ans;
        while (root)
        {
            if (root->data == val)
                return root;

            if (root->data > val)
            {
                ans = root;
                root = root->left;
            }
            else
                root = root->right;
        }
        return ans;
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
    Node *ans1 = s.Floor(root, 5);
    Node *ans2 = s.Floor(root, 12);
    cout << " Floor = " << ans1->data;
    cout << " Ceil = " << ans2->data;
    return 0;
}