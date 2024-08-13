// https://www.geeksforgeeks.org/problems/huffman-encoding3345/1
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

class cmp{
    public:
        bool operator()(node* a, node* b){
            return a -> data > b -> data;
        }
};

class Solution{
    private:
        void traverse(node* root, vector<string> &ans, string temp){
            if(root -> left == NULL && root -> right == NULL){
                ans.push_back(temp);
                return;
            }
            traverse(root -> left, ans, temp + '0');
            traverse(root -> right, ans, temp + '1');
        }
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int n){
		    priority_queue<node*, vector<node*>, cmp> pq;
		    for(int i = 0; i < n; i++){
		        node* temp = new node(f[i]);
		        pq.push(temp);
		    }
		    while(pq.size() > 1){
		        node* left = pq.top();
		        pq.pop();
		        node* right = pq.top();
		        pq.pop();
		        node* newNode = new node(left -> data + right -> data);
		        newNode -> left = left;
		        newNode -> right = right;
		        pq.push(newNode);
		    }
		    node* root = pq.top();
		    vector<string> ans;
		    string temp = "";
		    traverse(root, ans, temp);
		    return ans;
		}
};