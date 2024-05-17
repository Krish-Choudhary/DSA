// https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

Node* solve(Node* root, int &k, int node) {
    //base case
    if(root == NULL)
        return NULL;
        
    if(root->data == node) 
    {
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);


    //wapas
    if(leftAns != NULL && rightAns == NULL) 
    {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
    

}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

// Alternate approach
/*
bool findAncestors(Node* root, int target, vector<int>& ancestors) {
    if (root == nullptr)
        return false;

    if (root->data == target)
        return true;

    if (findAncestors(root->left, target, ancestors) || findAncestors(root->right, target, ancestors)) {
        ancestors.push_back(root->data);
        return true;
    }

    return false;
}
int kthAncestor(Node *root, int k, int node)
{
    vector<int> ancestors;

    // Find the ancestors of the target node
    if (!findAncestors(root, node, ancestors))
        return -1; // Target node not found

    // Check if k is within the range of ancestors
    int n = ancestors.size();
    if (k > n)
        return -1; // kth ancestor does not exist

    // Return the kth ancestor
    return ancestors[k - 1];
}
*/