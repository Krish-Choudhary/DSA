// https://leetcode.com/problems/edit-distance/
#include <bits/stdc++.h>
using namespace std;

/*
// Approach 1: Recurssion
class Solution {
private:
    int solve(string &word1, string &word2, int i, int j){
        if(i == word1.length()) return word2.length() - j;
        if(j == word2.length()) return word1.length() - i;
        int ans = 0;
        if(word1[i] == word2[j])    ans = solve(word1, word2, i + 1, j + 1);
        else{
            int insert = 1 + solve(word1, word2, i, j + 1);
            int del = 1 + solve(word1, word2, i + 1, j);
            int replace = 1 + solve(word1, word2, i + 1, j + 1);
            ans = min(insert, min(del, replace));
        }
        return ans;
    }
public:
    int minDistance(string word1, string word2) {
        return solve(word1, word2, 0, 0);
    }
};
*/


/*
// Approach 2: Recurssion + Memoization
class Solution {
private:
    int solve(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){
        if(i == word1.length()) return word2.length() - j;
        if(j == word2.length()) return word1.length() - i;
        if(dp[i][j] != -1)  return dp[i][j];
        int ans = 0;
        if(word1[i] == word2[j])    ans = solve(word1, word2, i + 1, j + 1, dp);
        else{
            int insert = 1 + solve(word1, word2, i, j + 1, dp);
            int del = 1 + solve(word1, word2, i + 1, j, dp);
            int replace = 1 + solve(word1, word2, i + 1, j + 1, dp);
            ans = min(insert, min(del, replace));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return solve(word1, word2, 0, 0, dp);
    }
};
*/

/*
// Approach 3: Tabulation
int minDistance(string word1, string word2) {
    int l1 = word1.length(), l2 = word2.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    for(int j = 0; j < l2; j++) dp[l1][j] = l2 - j;
    for(int i = 0; i < l1; i++) dp[i][l2] = l1 - i;
    for(int i = l1 - 1; i >= 0; i--){
        for(int j = l2 - 1; j >= 0; j--){
            int ans = 0;
            if(word1[i] == word2[j])    ans = dp[i + 1][j + 1];
            else{
                int insert = 1 + dp[i][j + 1];
                int del = 1 + dp[i + 1][j];
                int replace = 1 + dp[i + 1][j + 1];
                ans = min(insert, min(del, replace));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
*/


// Space optimisation
int minDistance(string word1, string word2) {
    int l1 = word1.length(), l2 = word2.length();
    if(l2 == 0) return l1;
    if(l1 == 0) return l2;
    vector<int> curr(l2 + 1, 0);
    vector<int> next(l2 + 1, 0);
    for(int j = 0; j < l2; j++) next[j] = l2 - j;
    for(int i = l1 - 1; i >= 0; i--){
        curr[l2] = l1 - i;      // base case
        for(int j = l2 - 1; j >= 0; j--){
            int ans = 0;
            if(word1[i] == word2[j])    ans = next[j + 1];
            else{
                int insert = 1 + curr[j + 1];
                int del = 1 + next[j];
                int replace = 1 + next[j + 1];
                ans = min(insert, min(del, replace));
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}