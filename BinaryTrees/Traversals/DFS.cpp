#include <bits/stdc++.h>
using namespace std;
 vector<int> ans;
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
// vector<int> inorder(Node *node) // LEFT ROOT RIGHT
// {
//     if (node == NULL)
//         return {};

//     inorder(node->left);
//     cout << " " << node->data;
//     inorder(node->right);
// }
// vector<int> postorder(Node *node) // LEFT RIGHT ROOT
// {
//     if (node == NULL)
//         return {};

//     postorder(node->left);
//     postorder(node->right);
//     cout << " " << node->data;
// }
   
    vector<int> preorder(Node *node) // ROOT LEFT RIGHT
    {
        if (node == NULL)
            return {};

        ans.push_back(node->data);
        preorder(node->left);
        preorder(node->right);
        return ans;
    }

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    // vector<int> ans1 = inorder(root);
    cout << endl;
    vector<int> ans2 = preorder(root);
    for (auto it : ans2)
    {
        cout << " " << it;
    }
    cout << endl;
    // vector<int> ans3 = postorder(root);
}