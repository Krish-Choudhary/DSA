// https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    private:
    int countNode(struct Node* root){
        if(root == NULL)    return 0;
        return 1 + countNode(root -> left) + countNode(root -> right);
    }
    
    bool isCBT(struct Node* root, int i, int n){
        if(root == NULL)    return true;
        if(i > n)   return false;
        else{
            return isCBT(root -> left, 2*i, n) && isCBT(root -> right, 2*i + 1, n);
        }
    }
    
    bool isMaxOrder(struct Node* root){
        if(root -> left == NULL && root -> right == NULL)   return true;
        else if(root -> left != NULL && root -> right == NULL)  return root -> data >= root -> left -> data;
        else{
            return root -> data >= root -> left -> data && root -> data >= root -> right -> data && isMaxOrder(root -> left) && isMaxOrder(root -> right);
        }
    }
    
    public:
    bool isHeap(struct Node* root) {
        int index = 1;
        int n = countNode(root);
        if(isCBT(root, index, n) && isMaxOrder(root))   return true;
        else    return false;
    }
};