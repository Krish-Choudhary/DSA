// https://www.naukri.com/code360/problems/lca-in-a-bst_981280?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

/*
Approach -1: Recursive
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    if(root == NULL)    return NULL;

    if(root -> data < P -> data && root -> data < Q -> data)    return  LCAinaBST(root -> right, P, Q);
    if(root -> data > P -> data && root -> data > Q -> data)    return LCAinaBST(root -> left, P, Q);
    return root;
}
TC = O(N)
SC = O(height)
*/

// Approach-2 : Iterative
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    while(root != NULL){
        if(root -> data < P -> data && root -> data < Q -> data)    root = root -> right;
        else if(root -> data > P -> data && root -> data > Q -> data)   root = root -> left;
        else    return root;
    }
    return NULL;
}
/*
TC = O(N)
SC = O(1)
*/