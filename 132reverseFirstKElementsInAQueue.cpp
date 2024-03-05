#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> s;
        int n = q.size();
        for(int i = 0; i < k; i++){
            s.push(q.front());
            q.pop();
        }
        for(int i = 0; i < k; i++){
            q.push(s.top());
            s.pop();
        }
        for(int i = 0; i < n - k; i++){
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};