// https://www.naukri.com/code360/problems/preorder-traversal-to-bst_893111?leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode{
public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi, int &i){
    if(i >= preorder.size())    return NULL;
    int curr = preorder[i];
    if(curr < mini || curr > maxi)    return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(curr);
    i++;
    root -> left = solve(preorder, mini, curr, i);
    root -> right = solve(preorder, curr, maxi, i);
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
}