// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int prev = arr[i] - difference;
            int tempAns = 0;
            if(dp.count(prev))  tempAns = dp[prev];
            dp[arr[i]] = 1 + tempAns;
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};