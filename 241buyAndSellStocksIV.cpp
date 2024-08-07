// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#include <bits/stdc++.h>
using namespace std;


// Same as previous question
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> next(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));
    for(int index = n - 1; index >= 0; index--){
        for(int buyAllowed = 0; buyAllowed <= 1; buyAllowed++){
            for(int totalTransactions = 1; totalTransactions <= k; totalTransactions++){
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
    return next[1][k];
}


/*
// Approach 1: Recurssion
class Solution {
private:
    int solve(int index, int operationNumber, int k, vector<int>& prices, int n){
        if(index == n)  return 0;
        if(operationNumber == 2 * k)    return 0;
        int profit = 0;
        if(operationNumber % 2 == 0){
            // buy allowed
            profit = max(solve(index + 1, operationNumber + 1, k, prices, n) - prices[index], solve(index + 1, operationNumber, k, prices, n));
        }
        else
            profit = max(solve(index + 1, operationNumber + 1, k, prices, n) + prices[index], solve(index + 1, operationNumber, k, prices, n));
        return profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return solve(0, 0, k, prices, prices.size());
    }
};
*/


/*
// Approach 2: Recurssion + Memoization
class Solution {
private:
    int solve(int index, int operationNumber, int k, vector<int>& prices, vector<vector<int>> dp){
        if(index == prices.size())  return 0;
        if(operationNumber == 2 * k)    return 0;
        if(dp[index][operationNumber] != -1)    return dp[index][operationNumber];
        int profit = 0;
        if(operationNumber % 2 == 0){
            // buy allowed
            profit = max(solve(index + 1, operationNumber + 1, k, prices, dp) - prices[index], solve(index + 1, operationNumber, k, prices, dp));
        }
        else
            profit = max(solve(index + 1, operationNumber + 1, k, prices, dp) + prices[index], solve(index + 1, operationNumber, k, prices, dp));
        dp[index][operationNumber] = profit;
        return profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        return solve(0, 0, k, prices, dp);
    }
};
*/


/*
// Approach 3: Tabulation
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
    for(int index = n - 1; index >= 0; index--){
        for(int operationNumber = 2 * k - 1; operationNumber >= 0; operationNumber--){
            int profit = 0;
            if(operationNumber % 2 == 0){
                // buy allowed
                profit = max(dp[index + 1][operationNumber + 1] - prices[index], dp[index + 1][operationNumber]);
            }
            else
                profit = max(dp[index + 1][operationNumber + 1] + prices[index], dp[index + 1][operationNumber]);
            dp[index][operationNumber] = profit;
        }
    }
    return dp[0][0];
}
*/

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<int> curr(2 * k + 1, 0);
    vector<int> next(2 * k + 1, 0);
    for(int index = n - 1; index >= 0; index--){
        for(int operationNumber = 2 * k - 1; operationNumber >= 0; operationNumber--){
            int profit = 0;
            if(operationNumber % 2 == 0){
                // buy allowed
                profit = max(next[operationNumber + 1] - prices[index], next[operationNumber]);
            }
            else
                profit = max(next[operationNumber + 1] + prices[index], next[operationNumber]);
            curr[operationNumber] = profit;
        }
        next = curr;
    }
    return next[0];
}