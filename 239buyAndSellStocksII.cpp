// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
#include <bits/stdc++.h>
using namespace std;

/*
// Approach 1: Recurssion
class Solution {
private:
    int solve(vector<int>& prices, int n, int index, bool buyAllowed){
        if(index == n)  return 0;
        int profit = 0;
        if(buyAllowed)
            profit = max(solve(prices, n, index + 1, false) - prices[index], solve(prices, n, index + 1, true));
        else
            profit = max(solve(prices, n, index + 1, true) + prices[index], solve(prices, n, index + 1, false));
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        return solve(prices, prices.size(), 0, true);
    }
};
*/


/*
// Approach 2: Recurssion + Memoization
class Solution {
private:
    int solve(vector<int>& prices, int n, int index, bool buyAllowed, vector<vector<int>> &dp){
        if(index == n)  return 0;
        if(dp[index][buyAllowed] != -1) return dp[index][buyAllowed];
        int profit = 0;
        if(buyAllowed)
            profit = max(solve(prices, n, index + 1, false, dp) - prices[index], solve(prices, n, index + 1, true, dp));
        else
            profit = max(solve(prices, n, index + 1, true, dp) + prices[index], solve(prices, n, index + 1, false, dp));
        dp[index][buyAllowed] = profit;
        return dp[index][buyAllowed];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, n, 0, true, dp);
    }
};
*/

/*
// Approach 3: Tabulation
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for(int index = n - 1; index >= 0; index--){
        for(int buyAllowed = 0; buyAllowed <= 1; buyAllowed++){
            int profit = 0;
            if(buyAllowed)
                profit = max(dp[index + 1][0] - prices[index], dp[index + 1][1]);
            else
                profit = max(dp[index + 1][1] + prices[index], dp[index + 1][0]);
            dp[index][buyAllowed] = profit;
        }
    }
    return dp[0][1];
}
*/


int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> curr(2, 0);
    vector<int> next(2, 0);
    for(int index = n - 1; index >= 0; index--){
        for(int buyAllowed = 0; buyAllowed <= 1; buyAllowed++){
            int profit = 0;
            if(buyAllowed)
                profit = max(next[0] - prices[index], next[1]);
            else
                profit = max(next[1] + prices[index], next[0]);
            curr[buyAllowed] = profit;
        }
        next = curr;
    }
    return next[1];
}