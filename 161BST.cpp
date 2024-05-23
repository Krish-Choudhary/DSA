#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root -> data)    root -> right = insertIntoBST(root -> right, d);
    else    root -> left = insertIntoBST(root -> left, d);

    return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        Node *temp = q.front();
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

Node* minVal(Node* root){
    if(root == NULL || root -> left == NULL)    return root;
    Node* temp = root;
    while(temp -> left != NULL){
        temp = temp -> left;
    }
    return temp;
}

Node* maxVal(Node* root){
    if(root == NULL || root -> right == NULL)    return root;
    Node* temp = root;
    while(temp -> right != NULL){
        temp = temp -> right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val){
    if(root == NULL)    return root;

    if(root -> data == val){
        // 0 child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        
        // 1 child
        if(root -> left != NULL && root -> right == NULL){  // left child
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        if(root -> left == NULL && root -> right != NULL){  // right child
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        
        // 2 child
        if(root -> left != NULL && root -> right != NULL){
            int mini = minVal(root -> right) -> data;
            // int maxi = maxVal(root -> left) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }
    }
    else if(root -> data > val){
        // goto left part
        root -> left = deleteFromBST(root -> left, val);
        return root;
    }
    else{
        // goto right part
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
}

int main(){
    Node* root = NULL;
    takeInput(root);
    cout << endl << endl;
    levelOrderTraversal(root);
    cout << endl << endl;
    deleteFromBST(root, 60);
    levelOrderTraversal(root);
    return 0;
}