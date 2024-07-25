// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
#include <bits/stdc++.h>
using namespace std;

/*
// Approach - 1: Recurssion
class Solution {
private:
    int solve(vector<int>& values, int i, int j){
        if(i + 1 == j)  return 0;   // i and j are adjacent i.e. only 2 edges
        int ans = INT_MAX;
        for(int k = i + 1; k < j; k++)
            ans = min(ans, values[i] * values[j] * values[k] + solve(values, i, k) + solve(values, k, j));
        return ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return solve(values, 0, n - 1);
    }
};
*/



/*
// Approach - 2: Recurssion + Memoization
class Solution {
private:
    int solve(vector<int>& values, int i, int j, vector<vector<int>> &dp){
        if(i + 1 == j)  return 0;   // i and j are adjacent i.e. only 2 edges
        if(dp[i][j] != -1)  return dp[i][j];
        dp[i][j] = INT_MAX;
        for(int k = i + 1; k < j; k++)
            dp[i][j] = min(dp[i][j], values[i] * values[j] * values[k] + solve(values, i, k, dp) + solve(values, k, j, dp));
        return dp[i][j];
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(values, 0, n - 1, dp);
    }
};
*/



/*
// Approach - 3: Tabulation
int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 2; j < n; j++){
            int ans = INT_MAX;
            for(int k = i + 1; k < j; k++)
                ans = min(ans, values[i] * values[j] * values[k] + dp[i][k] + dp[k][j]);
            dp[i][j] = ans;
        }
    }
    return dp[0][n - 1];
}
*/