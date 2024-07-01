// https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650
#include <bits/stdc++.h>
using namespace std;

int solve(int nStairs, vector<int> &dp) {
    if (nStairs < 0) return 0;
    if (nStairs == 0) return 1;
    if (dp[nStairs] != -1) return dp[nStairs];
    
    dp[nStairs] = (solve(nStairs - 2, dp) + solve(nStairs - 1, dp)) % 1000000007;
    return dp[nStairs];
}

int countDistinctWays(int nStairs) {
    vector<int> dp(nStairs + 1, -1);
    return solve(nStairs, dp);
}


/*
// Recurssion -> TLE
int countDistinctWays(int nStairs) {
    if(nStairs < 0)    return 0;
    if(nStairs == 0)    return 1;
    return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}
*/