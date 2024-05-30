// https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void heapify(vector<int> &arr, int n, int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[left] > arr[largest])   largest = left;
        if(right < n && arr[right] > arr[largest]) largest = right;
    
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        for(int i = 0; i < m; i++){
            a.push_back(b[i]);
        }
        n = n + m;
        for(int i = n/2 - 1; i >= 0; i--){
            heapify(a, n, i);
        }
    return a;
    }
};