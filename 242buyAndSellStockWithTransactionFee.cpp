// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
#include <bits/stdc++.h>
using namespace std;

// Same as best time to buy and sell stock II
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> curr(2, 0);
    vector<int> next(2, 0);
    for(int index = n - 1; index >= 0; index--){
        for(int buyAllowed = 0; buyAllowed <= 1; buyAllowed++){
            int profit = 0;
            if(buyAllowed)
                profit = max(next[0] - prices[index], next[1]);
                else
                profit = max(next[1] + prices[index] - fee, next[0]);
            curr[buyAllowed] = profit;
        }
        next = curr;
    }
    return next[1];
}