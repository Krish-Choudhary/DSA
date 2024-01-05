#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/next-smaller-element_1112581?leftPanelTabValue=PROBLEM

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);
    for(int i = n - 1; i >= 0; i--){
        while(st.top() >= arr[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}