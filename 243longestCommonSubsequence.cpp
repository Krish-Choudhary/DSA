// https://leetcode.com/problems/longest-common-subsequence/
#include <bits/stdc++.h>
using namespace std;

/*
// Approach 1: Recurssion
class Solution {
private:
    int solve(string text1, string text2, int i, int j){
        if(i == text1.length() || j == text2.length())    return 0;
        int ans = 0;
        if(text1[i] == text2[j])    ans = 1 + solve(text1, text2, i + 1, j + 1);
        else    ans = max(solve(text1, text2, i, j + 1), solve(text1, text2, i + 1, j));
        return ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2, 0, 0);
    }
};
*/


/*
// Approach 2: Recurssion + Memoization
class Solution {
private:
    int solve(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
        if(i == text1.length() || j == text2.length())    return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        int ans = 0;
        if(text1[i] == text2[j])    ans = 1 + solve(text1, text2, i + 1, j + 1, dp);
        else    ans = max(solve(text1, text2, i, j + 1, dp), solve(text1, text2, i + 1, j, dp));
        dp[i][j] = ans;
        return dp[i][j];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return solve(text1, text2, 0, 0, dp);
    }
};
*/

/*
// Approach 3: Tabulation
int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
    for(int i = text1.length() - 1; i >= 0; i--){
        for(int j = text2.length() - 1; j >= 0; j--){
            int ans = 0;
            if(text1[i] == text2[j])    ans = 1 + dp[i + 1][j + 1];
            else    ans = max(dp[i][j + 1], dp[i + 1][j]);
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
*/

int longestCommonSubsequence(string text1, string text2) {
    vector<int> next(text2.length() + 1, 0);
    vector<int> curr(text2.length() + 1, 0);
    for(int i = text1.length() - 1; i >= 0; i--){
        for(int j = text2.length() - 1; j >= 0; j--){
            int ans = 0;
            if(text1[i] == text2[j])    ans = 1 + next[j + 1];
            else    ans = max(curr[j + 1], next[j]);
            curr[j] = ans;
        }
        next = curr;
    }
    return curr[0];
}