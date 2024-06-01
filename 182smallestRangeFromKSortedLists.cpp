// https://www.naukri.com/code360/problems/smallest-range-from-k-sorted-list_1069356
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    int arrNumber;
    int index;
    node(int val, int arrNum, int index){
        data = val;
        arrNumber = arrNum;
        this -> index = index;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a -> data > b -> data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node*, vector<node*>, compare> minHeap;
    for(int i = 0; i < k; i++){
        node* temp = new node(a[i][0], i, 0);
        maxi = max(maxi, a[i][0]);
        minHeap.push(temp);
    }
    mini = minHeap.top() -> data;
    int start = mini, end = maxi;

    while(!minHeap.empty()){
        node* top = minHeap.top();
        minHeap.pop();
        mini = top -> data;
        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }
        if(top -> index + 1 < n){
            maxi = max(maxi, a[top -> arrNumber][top -> index + 1]);
            minHeap.push(new node(a[top -> arrNumber][top -> index + 1], top -> arrNumber, top -> index + 1));
        }
        else    break;
    }
    return end - start + 1;
}