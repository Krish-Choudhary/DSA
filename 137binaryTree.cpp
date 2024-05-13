#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL; // -1 is considered as NULL

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node *root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        node *temp = q.front();
        q.pop();

        if (temp == NULL){  // level traversed
            cout << endl;
            if (!q.empty())  q.push(NULL);
        }
        else{
            cout << temp->data << " ";
            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL)    q.push(temp->right);
        }
    }
}

void reverseLevelOrderTraversal(node *root){
    stack<node *> s;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        node *temp = q.front();
        q.pop();

        if (temp == NULL){
            s.push(NULL);
            if (!q.empty()) q.push(NULL);
        }
        else{
            s.push(temp);
            if(temp->right != NULL)    q.push(temp->right);
            if(temp->left != NULL)  q.push(temp->left);
        }
    }
    while (!s.empty()){
        node *temp = s.top();
        temp != NULL ? cout << temp->data << " " : cout << endl;
        s.pop();
    }
}

void inorder(node* root){
    // Recursive approach
    // if(root == NULL) return; // base case
    // // LNR
    // inorder(root -> left);
    // cout << root -> data << " ";
    // inorder(root -> right);

    // Iterative approach
    stack<node*> s;
    node* curr = root;
 
    while (curr != NULL || !s.empty()) {
        // Reach the left most Node of the curr Node
        while (curr != NULL) {
            // Place pointer to a tree node on the stack before traversing the node's left subtree
            s.push(curr);
            curr = curr->left;
        }
        // Current must be NULL at this point
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
 
        // we have visited the node and its left subtree.  Now, it's right subtree's turn
        curr = curr->right;
    }
}

void preorder(node* root){
    // Recursive approach
    // if(root == NULL) return; // base case
    // // NLR
    // cout << root -> data << " ";
    // preorder(root -> left);
    // preorder(root -> right);

    // Iterative approach
    if (root == NULL)   return;
 
    // Create an empty stack and push root to it
    stack<node*> s;
    s.push(root);
 
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (!s.empty()) {
        // Pop the top item from stack and print it
        node* temp = s.top();
        cout << temp -> data << " ";
        s.pop();
 
        // Push right and left children of the popped node to stack
        if (temp->right != NULL)    s.push(temp->right);
        if (temp->left != NULL)     s.push(temp->left);
    }
}

void postorder(node* root){
    // Recursive approach
    // if(root == NULL) return; // base case
    // // LRN
    // postorder(root -> left);
    // postorder(root -> right);
    // cout << root -> data << " ";

    // Iterative approach-1 using 2 stacks
    // if(root == NULL) return;
    // stack<node*> s1, s2;
    // s1.push(root);
    // while(!s1.empty()){
    //     node* curr = s1.top();
    //     s1.pop();
    //     s2.push(curr);
    //     if(curr -> left != NULL)    s1.push(curr -> left);
    //     if(curr -> right != NULL)    s1.push(curr -> right);
    // }
    // while(!s2.empty()){
    //     cout << s2.top() << " ";
    //     s2.pop();
    // }

    // Iterative approach-2 using 1 stacks
    if(root == NULL) return;
    stack<node*> s;
    s.push(root);
    node* prev = NULL;
    while(!s.empty()){
        node* curr = s.top();
        if(prev == NULL || prev -> left == curr || prev -> right == curr){
            if(curr -> left)    s.push(curr->left);
            else if(curr -> right)  s.push(curr->right);
            else {
                s.pop();
                cout << curr -> data << " ";
            }
        }
        else if (curr->left == prev) {
            if (curr->right)
                s.push(curr->right);
            else {
                s.pop();
                cout << curr -> data << " ";
            }

            /* go up the tree from right node and after
            coming back from right node process parent and
            pop stack */
        }
        else if (curr->right == prev) {
            s.pop();
            cout << curr -> data << " ";
        }
        prev = curr;
    }
}

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }

int main()
{
    node *root = NULL;
    // creating a tree
    root = buildTree(root);
    postorder(root);
    return 0;
}