// https://leetcode.com/problems/reducing-dishes/
#include <bits/stdc++.h>
using namespace std;

/*
// Approach -1: Recurssion
class Solution {
private:
    int solve(vector<int>& satisfaction, int index, int time, int n){
        if(index == n)  return 0;
        int include = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1, n);
        int exclude = solve(satisfaction, index + 1, time, n);
        return max(include, exclude);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction, 0, 0, satisfaction.size());
    }
};
*/


/*
// Approach -2: Recurssion + Memoization
class Solution {
private:
    int solve(vector<int>& satisfaction, int index, int time, int n, vector<vector<int>> &dp){
        if(index == n)  return 0;
        if(dp[index][time] != -1)   return dp[index][time];
        int include = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1, n, dp);
        int exclude = solve(satisfaction, index + 1, time, n, dp);
        dp[index][time] = max(include, exclude);
        return dp[index][time];
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(satisfaction, 0, 0, n, dp);
    }
};
*/


/*
// Approach -3: Tabulation
int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int index = n - 1; index >= 0; index--){
        for(int time = index; time >= 0; time--){
            int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
            int exclude = dp[index + 1][time];
            dp[index][time] = max(include, exclude);
        }
    }
    return dp[0][0];
}
*/


int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    int n = satisfaction.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for(int index = n - 1; index >= 0; index--){
        for(int time = index; time >= 0; time--){
            int include = satisfaction[index] * (time + 1) + next[time + 1];
            int exclude = next[time];
            curr[time] = max(include, exclude);
        }
        next = curr;
    }
    return next[0];
}
