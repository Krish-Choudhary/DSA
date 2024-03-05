#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int n, long long int k) {
    vector<long long> ans;
    deque<long long int> dq;
    
    // Checking for first window
    for(int i = 0; i < k; i++){
        if(A[i] < 0)    dq.push_back(i);
    }
    
    dq.empty() ? ans.push_back(0) : ans.push_back(A[dq.front()]);
    
    for(int i = k; i < n; i++){
        if(!dq.empty() && i - dq.front() >= k)  dq.pop_front();
        
        if(A[i] < 0)    dq.push_back(i);
        
        dq.empty() ? ans.push_back(0) : ans.push_back(A[dq.front()]);
    }
    return ans;
    
                                                 
 }