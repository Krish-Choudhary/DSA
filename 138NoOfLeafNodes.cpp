// https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

void inorder(Node* root, int &count){
    if(root == NULL)    return;
    // LNR
    inorder(root -> left, count);
    if(root -> left == NULL && root -> right == NULL)   count++;
    inorder(root -> right, count);
}   

int countLeaves(Node* root)
{
    int count = 0;
    inorder(root, count);
    return count;
}