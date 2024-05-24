// https://www.naukri.com/code360/problems/two-sum-in-a-bst_1062631
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void inorder(BinaryTreeNode<int>* root, vector<int> &inorderArr){
    if(root == NULL)    return;

    inorder(root -> left, inorderArr);
    inorderArr.push_back(root -> data);
    inorder(root -> right, inorderArr);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> inorderArr;
    inorder(root, inorderArr);
    int j = inorderArr.size() - 1;
    int i = 0;

    while( i < j){
        int sum = inorderArr[i] + inorderArr[j];
        if(sum == target)   return true;
        else if(sum > target)    j--;
        else    i++;
    }
    return false;
}