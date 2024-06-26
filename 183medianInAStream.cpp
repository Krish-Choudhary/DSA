// https://www.naukri.com/code360/problems/median-in-a-stream_975268
#include <bits/stdc++.h>
using namespace std;

int signum(int a, int b){
    if(a == b)  return 0;
    return a > b ? 1 : -1;
}

void callMedian(int element, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int &median){
    switch(signum(maxHeap.size(), minHeap.size())){
        case 0:
            if(element > median){
                minHeap.push(element);
                median = minHeap.top();
            }
            else{
                maxHeap.push(element);
                median = maxHeap.top();
            }
            break;
        case 1:
            if(element > median){
                minHeap.push(element);
                median = (maxHeap.top() + minHeap.top()) / 2;
            }
            else{
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(element);
                median = (maxHeap.top() + minHeap.top()) / 2;
            }
            break;
        case -1:
            if(element > median){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(element);
                median = (maxHeap.top() + minHeap.top()) / 2;
            }
            else{
                maxHeap.push(element);
                median = (maxHeap.top() + minHeap.top()) / 2;
            }
            break;
    }
    return;
}

vector<int> findMedian(vector<int> &arr, int n){
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = 0;
	for(int i = 0; i < n; i++){
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}
