// https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379
#include <bits/stdc++.h> 
using namespace std;

class node{
    public:
    int data;
    int arrNumber;
    int index;
    node(int data, int arrNumber, int index){
        this -> data = data;
        this -> arrNumber = arrNumber;
        this -> index = index;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a-> data > b-> data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> minHeap;
    
    for(int i = 0; i < k; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    while(!minHeap.empty()){
        node* temp = minHeap.top();
        ans.push_back(temp -> data);
        minHeap.pop();
        int arrNum = temp -> arrNumber;
        int index = temp -> index;
        if (index + 1 < kArrays[arrNum].size()) {
            node* next = new node(kArrays[arrNum][index + 1], arrNum, index + 1);
            minHeap.push(next);
        }
    }
    return ans;
}