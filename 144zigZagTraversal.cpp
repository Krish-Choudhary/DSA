// https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

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

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> result;
    	if(root == NULL)    return result;
    	queue<Node*> q;
    	q.push(root);
    	bool leftToRight = true;
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> ans(size);
    	    
    	    for(int i = 0; i < size; i++){
    	        Node* frontNode = q.front();
    	        q.pop();
    	        int index = leftToRight ? i : size - i - 1;
    	        ans[index] = frontNode -> data;
    	        if(frontNode -> left != NULL)   q.push(frontNode -> left);
    	        if(frontNode -> right != NULL)   q.push(frontNode -> right);
    	    }
    	    
    	    leftToRight = !leftToRight;
    	    
    	    for(auto i: ans){
    	        result.push_back(i);
    	    }
    	}
    	return result;
    }
};