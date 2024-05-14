// https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    pair<bool, int> isBalancedFast(Node* root){
        if(root == NULL)    return make_pair(true, 0);
        pair<bool, int> leftAns = isBalancedFast(root -> left);
        pair<bool, int> rightAns = isBalancedFast(root -> right);
        pair<bool, int> ans;
        ans.second = max(leftAns.second, rightAns.second) + 1;
        if(leftAns.first && rightAns.first && abs(leftAns.second - rightAns.second) <= 1)   ans.first = true;
        else    ans.first = false;
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        // if(root == NULL)    return true;
        // return isBalanced(root -> left) && isBalanced(root -> right) && abs(height(root -> left) - height(root -> right)) <= 1;
        
        return isBalancedFast(root).first;
        
    }
};