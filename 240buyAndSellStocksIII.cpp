// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
#include <bits/stdc++.h>
using namespace std;

/*
// Approach 1: Recurssion
class Solution {
private:
    int solve(vector<int>& prices, int n, int index, bool buyAllowed, int totalTransactions){
        if(index == n)  return 0;
        if(totalTransactions == 0)  return 0;
        int profit = 0;
        if(buyAllowed)
            profit = max(solve(prices, n, index + 1, false, totalTransactions) - prices[index], solve(prices, n, index + 1, true, totalTransactions));
        else
            profit = max(solve(prices, n, index + 1, true, totalTransactions - 1) + prices[index], solve(prices, n, index + 1, false, totalTransactions));
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        return solve(prices, prices.size(), 0, true, 2);
    }
};
*/


/*
// Approach 2: Recurssion + Memoization
class Solution {
private:
    int solve(vector<int>& prices, int n, int index, bool buyAllowed, vector<vector<vector<int>>> &dp, int totalTransactions){
        if(index == n)  return 0;
        if(totalTransactions == 0)  return 0;
        if(dp[index][buyAllowed][totalTransactions] != -1) return dp[index][buyAllowed][totalTransactions];
        int profit = 0;
        if(buyAllowed)
            profit = max(solve(prices, n, index + 1, false, dp, totalTransactions) - prices[index], solve(prices, n, index + 1, true, dp, totalTransactions));
        else
            profit = max(solve(prices, n, index + 1, true, dp, totalTransactions - 1) + prices[index], solve(prices, n, index + 1, false, dp, totalTransactions));
        dp[index][buyAllowed][totalTransactions] = profit;
        return dp[index][buyAllowed][totalTransactions];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, n, 0, true, dp, 2);
    }
};
*/

/*
// Approach 3: Tabulation
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for(int index = n - 1; index >= 0; index--){
        for(int buyAllowed = 0; buyAllowed <= 1; buyAllowed++){
            for(int totalTransactions = 1; totalTransactions <= 2; totalTransactions++){
                int profit = 0;
                if(buyAllowed)
                    profit = max(dp[index + 1][0][totalTransactions] - prices[index], dp[index + 1][1][totalTransactions]);
                else
                    profit = max(dp[index + 1][1][totalTransactions - 1] + prices[index], dp[index + 1][0][totalTransactions]);
                dp[index][buyAllowed][totalTransactions] = profit;
            }
        }
    }
    return dp[0][1][2];
}
*/


int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> next(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));
    for(int index = n - 1; index >= 0; index--){
        for(int buyAllowed = 0; buyAllowed <= 1; buyAllowed++){
            for(int totalTransactions = 1; totalTransactions <= 2; totalTransactions++){
                int profit = 0;
                if(buyAllowed)
                    profit = max(next[0][totalTransactions] - prices[index], next[1][totalTransactions]);
                else
                    profit = max(next[1][totalTransactions - 1] + prices[index], next[0][totalTransactions]);
                curr[buyAllowed][totalTransactions] = profit;
            }
        }
        next = curr;
    }
    return next[1][2];
}