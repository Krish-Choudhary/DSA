#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/queue-reversal/1

class Solution
{
    void reverseQueue(queue<int>& q){
        // base case
        if (q.size() == 0)
            return ;
 
        int fr = q.front();
        q.pop();

        reverseQueue(q);
        q.push(fr);
    }
    
    public:
    queue<int> rev(queue<int> q){
        reverseQueue(q);
        return q;
    }
    /*
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;
        while(!q.empty()){
            int element = q.front();
            q.pop();
            s.push(element);
        }
        while(!s.empty()){
            int element = s.top();
            s.pop();
            q.push(element);
        }
        return q;
    }
    */
};