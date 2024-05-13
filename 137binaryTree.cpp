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

int main()
{
    node *root = NULL;
    // creating a tree
    root = buildTree(root);
    reverseLevelOrderTraversal(root);
    return 0;
}