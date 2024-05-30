// https://www.naukri.com/code360/problems/convert-bst-to-min-heap_920498
#include <bits/stdc++.h> 
using namespace std;

class BinaryTreeNode {		
public :
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(int data) {
	this -> left = NULL;
	this -> right = NULL;
	this -> data = data;
	}
};

void inorder(BinaryTreeNode* root, vector<int> &arr){
	if(root == NULL)	return;
	inorder(root -> left, arr);
	arr.push_back(root -> data);
	inorder(root -> right, arr);
}

void populate(BinaryTreeNode* &root, vector<int> arr, int &i){
	if(root == NULL)	return;
	root -> data = arr[i++];
	populate(root -> left, arr, i);
	populate(root -> right, arr, i);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> arr;
	inorder(root, arr);
	int i = 0;
	populate(root, arr, i);
	return root;
}