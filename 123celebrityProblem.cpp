#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
// TC = O(n)
// SC = O(n)
int celebrity(vector<vector<int> >& M, int n){
        stack<int> s;
        //step1: push all element in stack
        for(int i=0; i<n; i++) {
            s.push(i);
        }   
        
        //step2: get 2 elements and copare them
        
        while(s.size() > 1) {
            
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(M[a][b] == 1)    s.push(b);
            else    s.push(a);
        }
        int ans = s.top();
        //step3: single element in stack is potential celeb
        //so verify it
        
        int zeroCount = 0;
        int oneCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[ans][i] == 0)  zeroCount++;
            if(M[i][ans] == 1)  oneCount++;
        }
        
        //all zeroes
        if(zeroCount != n || oneCount != n-1)   return -1;
        
        return ans;
        
    }