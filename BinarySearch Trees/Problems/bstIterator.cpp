
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
    TreeNode(int x)
    {
        left = NULL;
        right = NULL;
        val = x;
    }
};
class BSTIterator
{
private:
    stack<TreeNode *> st;
    void pushAll(TreeNode *root)
    {
        if (!root)
            return;

        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->right->left = new TreeNode(7);

    BSTIterator bSTIterator(root);
    cout << bSTIterator.next();
    cout << endl;
    cout << bSTIterator.next();
    cout << endl;
    cout << bSTIterator.hasNext();
    cout << endl;
    cout << bSTIterator.next();
    cout << endl;
    cout << bSTIterator.hasNext();
    cout << endl;
    cout << bSTIterator.next();
    cout << endl;
    cout << bSTIterator.hasNext();
    cout << endl;
    cout << bSTIterator.next();
    cout << endl;
    cout << bSTIterator.hasNext();
    cout << endl;
    return 0;
}