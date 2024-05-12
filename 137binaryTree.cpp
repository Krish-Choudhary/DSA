#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){
    int data;
    cout << "Enter the data: ";
    cin >> data;
    root = new node(data);

    if(data == -1)  return NULL;            // -1 is considered as NULL

    cout << "Enter data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void levelOrderTraversal(node* root){
    
}

int main(){
    node* root = NULL;
    // creating a tree
    root = buildTree(root);
    return 0;
}