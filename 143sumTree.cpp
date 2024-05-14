// https://www.geeksforgeeks.org/problems/sum-tree/1
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

class Solution
{
    pair<bool, int> isSumTreeFast(Node* root){
        if(root == NULL)    return make_pair(true, 0);
        if(root -> left == NULL && root -> right == NULL)   return make_pair(true, root -> data);
        pair<bool, int> left = isSumTreeFast(root -> left);
        pair<bool, int> right = isSumTreeFast(root -> right);
        if(left.first && right.first && left.second + right.second == root -> data) return make_pair(true, left.second + right.second + root -> data);
        else    return make_pair(false, left.second + right.second + root -> data);
    }
    public:
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};