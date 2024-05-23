// https://www.naukri.com/code360/problems/validate-bst_981275?leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h>
using namespace std;

template <typename T>
    class BinaryTreeNode 
    {
      public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

bool isBST(BinaryTreeNode<int> *root, int min, int max){
    if(root == NULL)    return true;
    if(root -> data < max && root -> data > min){
        bool leftAns = isBST(root -> left, min, root -> data);
        bool rightAns = isBST(root -> right, root -> data, max);
        return leftAns && rightAns;
    }
    else    return false;
}

bool validateBST(BinaryTreeNode<int>* root) 
{
   isBST(root, INT_MIN, INT_MAX);
}