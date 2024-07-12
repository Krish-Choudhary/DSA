// https://www.naukri.com/code360/problems/number-of-ways_3755252
#include <bits/stdc++.h>
using namespace std;

/*
// Approach - 1: Recurssion
int findWays(vector<int> &num, int tar){
    if(tar < 0) return 0;
    if(tar == 0)    return 1;
    int ans = 0;

    for(int number: num)    ans += findWays(num, tar - number);
    return ans;
}
*/


/*
// Approach - 2: Recurssion + Memoization
int solve(vector<int> &num, int tar, vector<int> &dp){
    if(tar < 0) return 0;
    if(tar == 0)    return 1;
    if(dp[tar] != -1)   return dp[tar];
    int ans = 0;

    for(int number: num)    ans += solve(num, tar - number, dp);
    dp[tar] = ans;
    return dp[tar];
}

int findWays(vector<int> &num, int tar){
    vector<int> dp(tar + 1, -1);
    return solve(num, tar, dp);
}
*/



// Approach - 3: Tabulation
int findWays(vector<int> &num, int tar){
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= tar; i++){
      for(int number : num){
        if(i - number >= 0)   dp[i] += dp[i - number];
      }
    }
    return dp[tar];
}