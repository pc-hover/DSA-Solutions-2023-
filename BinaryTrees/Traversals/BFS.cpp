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
// push element into queue
// take out elements from queue nd check if left and right exists
// if yes then push them into the queue
// then remove add cuurent element into ans vector<vector

vector<vector<int>> levelorder(Node *root) // LEVEL TRAVERSAL
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);

            level.push_back(node->data);
        }
        ans.push_back(level);
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

    vector<vector<int>> ans = levelorder(root);
    for (const auto &row : ans)
    {
        for (const auto &column : row)
        {
            cout << " " << column;
        }
        cout << endl;
    }
}