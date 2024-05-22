// https://www.naukri.com/code360/problems/search-in-bst_1402878?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode{
public:
    int data;
    BinaryTreeNode *left, *right;
    BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
    BinaryTreeNode(int x) : data(x), left(NULL), right(NULL) {}
    BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
};


// Approach-1 : Recurssive
// TC = O(log N), worst O(height) = worst O(N)
// SC = O(height) = worst O(N)
// bool searchInBST(BinaryTreeNode<int> *root, int x) {
//     if(root == NULL)    return false;

//     if(x == root -> data)   return true;
//     else if(x > root -> data)   return searchInBST(root -> right, x);
//     else    return searchInBST(root -> left, x);
// }


// Approach-2 : Iterative
// TC = O(log N), worst O(height) = worst O(N)
// SC = O(1)
bool searchInBST(BinaryTreeNode *root, int x) {
    if(root == NULL)    return false;
    if(x == root -> data)   return true;

    BinaryTreeNode *temp = root;
    while(temp != NULL){
        if(temp -> data == x)   return true;
        if(x > temp -> data)    temp = temp -> right;
        else    temp = temp -> left;
    }
    return false;
}