// https://www.codingninjas.com/studio/problems/largest-rectangle-in-a-histogram_1058184
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElementIndex(vector<int> arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n - 1; i >= 0; i--){
        while(s.top() != -1 && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
    
vector<int> prevSmallerElementIndex(vector<int> arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0; i<n; i++) {
        while(s.top() != -1 && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans; 
}
    
int largestRectangle(vector<int>& heights) {
    int n= heights.size();
        
    vector<int> next(n);
    next = nextSmallerElementIndex(heights, n);
            
    vector<int> prev(n);
    prev = prevSmallerElementIndex(heights, n);
        
    int area = INT_MIN;
    for(int i=0; i<n; i++) {
        int l = heights[i];
            
        if(next[i] == -1) {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        area = max(area, l * b);
    }
    return area;
}
