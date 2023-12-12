#include <bits/stdc++.h>
using namespace std;
// https://youtu.be/S0Bwgtn32uI?si=Akgz54mHCN4bhj6n
// https://youtu.be/Rezetez59Nk?si=EBKkI4vz-lJwgegK
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
    int maxdepth(Node *root)
    {
        if (root == NULL)
            return 0;

        int lh = maxdepth(root->left);
        int rh = maxdepth(root->right);

        return 1 + max(lh, rh);
    }

    // TC->O(N)
    // SC->O(N) //Worst case skew
    int maxi = 0;
    int findMax(Node *root)
    {
        if (root == NULL)
            return 0;

        int lh = findMax(root->left);
        int rh = findMax(root->right);

        maxi = max(lh + rh, maxi);

        return 1 + max(lh, rh);
    }
    int diameterBT(Node *root)
    {
        int x = findMax(root);
        return maxi;
    }

    // issue with this code the maxdepth function of pepcoding requires -1 return so the height of tree is 0ne lessaccordingly following coe is written need to debig this
    int diameter(Node *root)
    {
        if (root == NULL)
            return 0;
        // case 1 -> Both ends of diameter lies on LHS
        int ld = diameter(root->left);
        // case 2 -> Both ends of diameter lies on RHS
        int rd = diameter(root->right);
        // case 3 -> One end of diameter lies on  LHS and other in RHS
        int f = maxdepth(root->left) + maxdepth(root->right) + 2;

        int dia = max(ld, max(rd, f));
        return dia;
    }
};

int main()
{
    /*


     1
   /   \
  2     3
       / \
      4   6
     /     \
    5       7
   /         \
  8           9


    */
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->right->left = new Node(4);
    root->right->right = new Node(6);

    root->right->right->right = new Node(7);
    root->right->left->left = new Node(5);

    root->right->left->left->left = new Node(8);
    root->right->right->right->right = new Node(9);

    Solution s;
    cout << "Diameter of the tree is " << s.diameterBT(root);
    cout << "\nDiameter of the tree is " << s.maxdepth(root);
    cout << "\nDiameter of the tree is " << s.diameter(root);
}