// https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
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
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2 == NULL)    return true;
        if(r1 == NULL)  return false;   // both null condition is already checked so they are not equal
        if(r2 == NULL)  return false;   // both null condition is already checked so they are not equal
        if(r1 -> data != r2 -> data)    return false;
        
        return isIdentical(r1 -> left, r2 -> left) && isIdentical(r1 -> right, r2 -> right);
    }
};