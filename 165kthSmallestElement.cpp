// https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTabValue=SOLUTION

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode 
{
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

/*
Approach-1: Inorder traversal
int solve(BinaryTreeNode<int>* root, int &i, int k){
    if(root == NULL)    return -1;

    // Inorder: LNR
    // L
    int left = solve(root -> left, i, k);
    if(left != -1)  return left;

    // N
    i++;
    if(i == k)  return root -> data;

    // R
    return solve(root -> right, i, k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i = 0;
    return solve(root, i, k);
}

TC = O(N)
SC = O(Height)
*/

/*
Approach-2: Morris traversal
int morrisTraversal(BinaryTreeNode<int>* root, int k) {
    BinaryTreeNode<int>* curNode = root;

    while (curNode != NULL) {
        if (curNode->left == NULL) {
            k = k - 1;

            // If 'curNode' is 'k-th' smallest node
            if (k == 0) {
                return curNode->data;
            }
            curNode = curNode->right;
        } else {
            BinaryTreeNode<int>* prev = curNode->left;

            // Find rightmost child node of 'curNode'
            while (prev->right != NULL && prev->right != curNode) {
                prev = prev->right;
            }

            // If rightmost node is leaf node then
            // Make a connection between rightmost node and 'curNode'
            if (prev->right == NULL) {
                prev->right = curNode;
                curNode = curNode->left;
            }

            else {
                prev->right = NULL;
                k = k - 1;
                if (k == 0) {
                    // If 'curNode' is 'k-th' smallest node
                    return (curNode->data);
                }
                curNode = curNode->right;
            }
        }
    }

    // If number of nodes less than 'k'
    return -1;
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Find 'k-th' smallest node with help of morris traversal
    return morrisTraversal(root, k);
}
TC = O(N)
SC = O(1)
*/