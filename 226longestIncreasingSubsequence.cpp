// https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
#include <bits/stdc++.h>
using namespace std;

/*
// Approach -1: Recurssion
class Solution{
    private:
    int solve(int n, int a[], int currIndex, int prevIndex){
        if(currIndex == n)  return 0;
        int include = 0;
        if(prevIndex == -1 || a[currIndex] > a[prevIndex])
            include = 1 + solve(n, a, currIndex + 1, currIndex);
        int exclude = solve(n, a, currIndex + 1, prevIndex);
        return max(include, exclude);
    }
    public:
    int longestSubsequence(int n, int a[]){
       return solve(n, a, 0, -1);
    }
};
*/


/*
// Approach -2: Recurssion + Memoization
// As prevIndex can be -1, so add +1 everywhere in dp array
class Solution{
    private:
    int solve(int n, int a[], int currIndex, int prevIndex, vector<vector<int>> &dp){
        if(currIndex == n)  return 0;
        if(dp[currIndex][prevIndex + 1] != -1)  return dp[currIndex][prevIndex + 1];
        int include = 0;
        if(prevIndex == -1 || a[currIndex] > a[prevIndex])
            include = 1 + solve(n, a, currIndex + 1, currIndex, dp);
        int exclude = solve(n, a, currIndex + 1, prevIndex, dp);
        dp[currIndex][prevIndex + 1] = max(include, exclude);
        return dp[currIndex][prevIndex + 1];
    }
    public:
    int longestSubsequence(int n, int a[]){
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(n, a, 0, -1, dp);
    }
};
*/


/*
// Approach -3: Tabulation
// As prevIndex can be -1, so add +1 everywhere in dp array
class Solution{
    public:
    int longestSubsequence(int n, int a[]){
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int currIndex = n - 1; currIndex >= 0; currIndex--){
            for(int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--){
                int include = 0;
                if(prevIndex == -1 || a[currIndex] > a[prevIndex])
                    include = 1 + dp[currIndex + 1][currIndex + 1];
                int exclude = dp[currIndex + 1][prevIndex + 1];
                dp[currIndex][prevIndex + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
};
*/


/*
// Space optimisation
// As prevIndex can be -1, so add +1 everywhere in dp array
int longestSubsequence(int n, int a[]){
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for(int currIndex = n - 1; currIndex >= 0; currIndex--){
        for(int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--){
            int include = 0;
            if(prevIndex == -1 || a[currIndex] > a[prevIndex])
                include = 1 + next[currIndex + 1];
            int exclude = next[prevIndex + 1];
            curr[prevIndex + 1] = max(include, exclude);
        }
        next = curr;
    }
    return next[-1 + 1];
}
*/


// TC: O(NlogN)
// SC: O(N)
int longestSubsequence(int n, int a[]){
    if(n == 0)  return 0;
    vector<int> ans;
    ans.push_back(a[0]);
        
    for(int i = 1; i < n; i++){
        if(a[i] > ans.back())   ans.push_back(a[i]);
        else{
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }
    return ans.size();
}