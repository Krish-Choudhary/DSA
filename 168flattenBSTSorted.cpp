// https://www.naukri.com/code360/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

void inorder(TreeNode<int>* root, vector<TreeNode<int>*> &inorderArr){
    if(root == NULL)    return;

    inorder(root -> left, inorderArr);
    inorderArr.push_back(root);
    inorder(root -> right, inorderArr);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<TreeNode<int>*> inorderArr;
    inorder(root, inorderArr);
    int n = inorderArr.size();
    TreeNode<int>* curr = inorderArr[0];
    curr -> left = NULL;
    for(int i = 1; i < n; i++){
        curr -> right = inorderArr[i];
        curr -> left = NULL;
        curr = curr -> right;
    }
    if (n > 1) {
        inorderArr[n - 1]->left = NULL;
        inorderArr[n - 1]->right = NULL;
    }
    return inorderArr[0];
}
