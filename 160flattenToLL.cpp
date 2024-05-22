// https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root;
        while(curr != NULL){
            if(curr -> left){
                Node* pred = curr -> left;
                while(pred -> right)    pred = pred -> right;
                pred -> right = curr -> right;
                curr -> right = curr -> left;   // saving left part
                curr -> left = NULL;            // making left part NULL
            }
            curr = curr -> right;
        }
    }
};