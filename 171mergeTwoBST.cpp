// https://www.naukri.com/code360/problems/h_920474?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inorder(TreeNode* root, vector<int> &inorderArr){
    if(root == NULL)    return;

    inorder(root -> left, inorderArr);
    inorderArr.push_back(root -> data);
    inorder(root -> right, inorderArr);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2){
    vector<int> inorderArr;
    inorder(root1, inorderArr);
    inorder(root2, inorderArr);
    sort(inorderArr.begin(), inorderArr.end());
    return inorderArr;
}