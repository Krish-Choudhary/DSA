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


/*
void inorder(TreeNode<int> *root, vector<int> &inorderArray)
{
    if (root == NULL)    return;
    
    inorder(root->left, inorderArray);
    inorderArray.push_back(root->data);
    inorder(root->right, inorderArray);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{

    if (root == NULL)   return root;
    
    vector<int> inorderArray;
    inorder(root, inorderArray);
    TreeNode<int> *newRoot = new TreeNode<int>(inorderArray[0]);
    TreeNode<int> *curr = newRoot;

    for (int i = 1; i < inorderArray.size(); i++)
    {

        TreeNode<int> *temp = new TreeNode<int>(inorderArray[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
}
*/