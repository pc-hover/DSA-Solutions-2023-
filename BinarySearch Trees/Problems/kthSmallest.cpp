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
    TreeNode(int item)
    {
        left = NULL;
        right = NULL;
        val = item;
    }
};
class Solution
{
public:
 int kthSmallest(TreeNode* root, int k) {
    if(!root)return -1;
int count=0;
    while(root)
    {
        if(root->left)
        {
            TreeNode* temp = root->left;
            while(temp->right !=NULL && temp->right !=root)
            {
                temp=temp->right;
            }
            if(temp->right==NULL)
            {
                temp->right=root;
                root=root->left;
            }
            if(temp->right == root)//this mean i have already visited the left subtrree so i will print current root and move to right
            {
             temp->right=NULL;
        count++;
        if(count==k) {return root->val;}
            
                root=root->right;
            }
        }
        else
        {
               count++;
        if(count==k) {return root->val;}
            
            root= root->right;
        }
    }
    return -1;
    }
 int kthLargest(TreeNode* root, int k) {
    vector<int> inorder;
    if(!root)return -1;
int count=0;
    while(root)
    {
        if(root->left)
        {
            TreeNode* temp = root->left;
            while(temp->right !=NULL && temp->right !=root)
            {
                temp=temp->right;
            }
            if(temp->right==NULL)
            {
                temp->right=root;
                root=root->left;
            }
            if(temp->right == root)//this mean i have already visited the left subtrree so i will print current root and move to right
            {
             temp->right=NULL;
                inorder.push_back(root->val);
        count++;
                root=root->right;
            }
        }
        else
        {
               count++;
            inorder.push_back(root->val);
            root= root->right;
        }
    }
   
    return inorder[inorder.size()-k];
    }
   
};
int main()
{
    struct TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    Solution s;
    int key=3;
    // cout<< s.kthSmallest(root,key);
    cout<<endl;
    cout<< s.kthLargest(root,1);


    return 0;
}
