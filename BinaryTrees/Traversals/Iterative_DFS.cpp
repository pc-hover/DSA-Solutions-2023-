// iterative approach
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
vector<int> inorder(Node *root) // LEFT ROOT RIGHT
{
    vector<int> ans;
    stack<Node *> st;
    Node *node = root;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty() == true)
                break;

            node = st.top(); // sending back to root
            st.pop();

            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}
vector<int> postorder(Node *root) // LEFT RIGHT ROOT
{
    vector<int> ans;
    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);

        if (root->left != NULL)
            st1.push(root->left);
        if (root->right != NULL)
            st1.push(root->right);
    }
    while (!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}

vector<int> preorder(Node *root) // ROOT LEFT RIGHT
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        ans.push_back(root->data);

        if (root->right != NULL)
            st.push(root->right);
        if (root->left != NULL)
            st.push(root->left);
    }
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

    vector<int> ans1, ans2, ans3;
    ans1 = inorder(root);
    ans2 = preorder(root);
    ans3 = postorder(root);

    for (auto it : ans1)
    {
        cout << " " << it;
    }
    cout << endl;
    for (auto it : ans2)
    {
        cout << " " << it;
    }
    cout << endl;
    for (auto it : ans3)
    {
        cout << " " << it;
    }
}