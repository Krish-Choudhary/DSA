// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for(int i = 0; i < n; i++)  minHeap.push(arr[i]);
    long long ans = 0;
    while(minHeap.size() > 1){
        long long a = minHeap.top();
        minHeap.pop();
        long long b = minHeap.top();
        minHeap.pop();
        long long sum = a + b;
        ans += sum;
        minHeap.push(sum);
    }
    return ans;
}