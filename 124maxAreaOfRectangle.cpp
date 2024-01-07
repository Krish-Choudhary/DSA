#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution{
  public:
    void find_prev(int* arr, int n, vector<int>& prev){
        
        stack<int> s;
        prev[0]=-1;
        
        s.push(0);
        for(int i=1; i<n; i++){
            int num = arr[i];
            while(!s.empty() && arr[s.top()]>=num) s.pop();
            
            if(s.empty()) prev[i] = -1;
            else prev[i] = s.top();
            s.push(i);
        }
        return ;
    }
    
    void find_next(int* arr, int n, vector<int>& next){
        
        stack<int> s;
        next[n-1]=n;
        
        s.push(n-1);
        for(int i=n-2; i>=0; i--){
            int num = arr[i];
            while(!s.empty() && arr[s.top()]>=num) s.pop();
            
            if(s.empty()) next[i] = n;
            else next[i] = s.top();
            s.push(i);
        }
        return ;
    }
    int solve(int* arr, int n){
        vector<int> prev(n, -1);
        find_prev(arr, n, prev);
        vector<int> next(n, n);
        find_next(arr, n, next);
        int ans = 0;
        for(int i=0; i<n; i++){
            int len = next[i]-prev[i]-1;
            ans = max(ans, len*arr[i]);
        }
        return ans;
        
    }


    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int ans = solve(M[0], m);
        for(int i=1; i<n; i++){
            //first update the array
            for(int j=0; j<m; j++){
                if(M[i][j]!=0)
                    M[i][j] = M[i-1][j]+M[i][j];
                else 
                    M[i][j] =0;
            }
            
            //calculate answer for this 
            ans = max(ans, solve(M[i], m) );
        }
        return ans;
    }
};
