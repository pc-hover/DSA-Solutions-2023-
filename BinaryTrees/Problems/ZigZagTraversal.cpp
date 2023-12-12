
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->right = NULL;
        this->left = NULL;
    }
    Node()
    {
        this->data = 0;
        this->right = NULL;
        this->left = NULL;
    }
};
class Solution
{

public:
    vector<vector<int>> zigzagLevelOrder(Node *root)
    {

        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<Node *> Q;
        Q.push(root);
        // flag=1 L->R
        // flag=0 R->L
        bool flag = true;

        while (!Q.empty())
        {
            int size = Q.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++)
            {
                Node *node = Q.front();
                Q.pop();

                int index = (flag) ? i : size - 1 - i; // if R->L then start placing elements from last to 0 in row
                row[index] = node->data;

                if (node->left != NULL)
                    Q.push(node->left);
                if (node->right != NULL)
                    Q.push(node->right);
            }
            flag = !flag;
            ans.push_back(row);
        }
        return ans;
    }
};
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution s;
    vector<vector<int>> ans = s.zigzagLevelOrder(root);
    for (auto it : ans)
    {
        for (auto it2 : it)
        {
            cout << " " << it2;
        }
    }
    return 0;
}