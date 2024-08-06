// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int maxi = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < n; i++){
        minPrice = min(minPrice, prices[i]);
        maxi = max(maxi, prices[i] - minPrice);
    }
    return maxi;
}