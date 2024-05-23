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

int main(){
    Node* root = NULL;
    takeInput(root);
    cout << endl << endl;
    levelOrderTraversal(root);
    return 0;
}