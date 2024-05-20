// https://www.geeksforgeeks.org/problems/burning-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    Node* createParentMapping(Node* root, map<Node*, Node*> &nodeToParent, int target){
        // create mapping and return target node,
        // because we are getting integer target in input not the node
        Node* res = NULL;
        nodeToParent[root] = NULL;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front -> data == target) res = front;
            
            if(front -> left){
                nodeToParent[front -> left] = front;
                q.push(front -> left);
            }
            if(front -> right){
                nodeToParent[front -> right] = front;
                q.push(front -> right);
            }
        }
        return res;
    }
    int burnTree(Node* root, map<Node*, Node*> &nodeToParent){
        map<Node*, bool> visited;
        queue<Node*> q;
        q.push(root);
        visited[root] = true;
        int ans = 0;
        
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            
            for(int i = 0; i < size; i++){
                Node* front = q.front();
                q.pop();
                
                if(front -> left && !visited[front -> left]){
                    flag = true;
                    q.push(front -> left);
                    visited[front -> left] = true;
                }
                if(front -> right && !visited[front -> right]){
                    flag = true;
                    q.push(front -> right);
                    visited[front -> right] = true;
                }
                Node* parent = nodeToParent[front];
                if(parent && !visited[parent]){
                    flag = true;
                    q.push(parent);
                    visited[parent] = true;
                }
            }
            if(flag == true)    ans++;
        }
        return ans;
    }
  public:
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, nodeToParent, target);
        return burnTree(targetNode, nodeToParent);
    }
};