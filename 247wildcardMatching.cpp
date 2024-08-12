// https://leetcode.com/problems/wildcard-matching/
#include <bits/stdc++.h>
using namespace std;

/*
// Approach 1: Recurssion
class Solution {
private:
    bool solve(string &s, string &p, int i, int j){
        if(i < 0 && j < 0)  return true;
        if(i >= 0 && j < 0) return false;
        if(i < 0 && j >= 0){
            for(int k = 0; k <= j; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(s[i] == p[j] || p[j] == '?') return solve(s, p, i - 1, j - 1);
        else if(p[j] == '*')    return solve(s, p, i - 1, j) || solve(s, p, i, j - 1);
        else    return false;
    }
public:
    bool isMatch(string &s, string &p) {
        return solve(s, p, s.length() - 1, p.length() - 1);
    }
};
*/


/*
// Approach 2: Recurssion + Memoization
class Solution {
private:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i < 0 && j < 0)  return true;
        if(i >= 0 && j < 0) return false;
        if(i < 0 && j >= 0){
            for(int k = 0; k <= j; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1)  return dp[i][j];

        if(s[i] == p[j] || p[j] == '?') dp[i][j] = solve(s, p, i - 1, j - 1, dp);
        else if(p[j] == '*')    dp[i][j] = solve(s, p, i - 1, j, dp) || solve(s, p, i, j - 1, dp);
        else    dp[i][j] = false;
        return dp[i][j];
    }
public:
    bool isMatch(string &s, string &p) {
        vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
        return solve(s, p, s.length() - 1, p.length() - 1, dp);
    }
};
*/


/*
// Approach 3: Tabulation
bool isMatch(string &s, string &p) {
    int l1 = s.length(), l2 = p.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    dp[0][0] = true;

    for(int j = 1; j <= l2; j++){
        bool flag = true;
        for(int k = 1; k <= j; k++){
            if(p[k - 1] != '*'){
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
            else if(p[j - 1] == '*')    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else    dp[i][j] = false;
        }
    }
    return dp[l1][l2];
}
*/


bool isMatch(string &s, string &p) {
        int l1 = s.length(), l2 = p.length();
        vector<int> curr(l2 + 1, 0);
        vector<int> prev(l2 + 1, 0);
        prev[0] = true;

        for(int j = 1; j <= l2; j++){
            bool flag = true;
            for(int k = 1; k <= j; k++){
                if(p[k - 1] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') curr[j] = prev[j - 1];
                else if(p[j - 1] == '*')    curr[j] = prev[j] || curr[j - 1];
                else    curr[j] = false;
            }
            prev = curr;
        }
        return prev[l2];
    }