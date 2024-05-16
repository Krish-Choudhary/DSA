// https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 


vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if(root == NULL)    return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        while(temp != NULL){
            if(temp -> left != NULL)    q.push(temp -> left);
            ans.push_back(temp -> data);
            temp = temp -> right;
        }
    }
    return ans;
}