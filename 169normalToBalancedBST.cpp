#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode{
public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void inorder(TreeNode<int>* root, vector<int> &inorderArr){
    if(root == NULL)    return;

    inorder(root -> left, inorderArr);
    inorderArr.push_back(root -> data);
    inorder(root -> right, inorderArr);
}

TreeNode<int>* inorderToBST(int start, int end, vector<int> inorderArr){
    if(start > end) return NULL;
    
    int mid = start + (end - start) / 2;
    TreeNode<int>* root = new TreeNode<int>(inorderArr[mid]);
    root -> left = inorderToBST(start, mid - 1, inorderArr);
    root -> right = inorderToBST(mid + 1, end, inorderArr);
    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorderArr;
    inorder(root, inorderArr);
    return inorderToBST(0, inorderArr.size() - 1, inorderArr);
}