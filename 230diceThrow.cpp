// https://www.geeksforgeeks.org/problems/dice-throw5349/1
#include <bits/stdc++.h>
using namespace std;


/*
// Approach 1: Recurssion
long long noOfWays(int faces, int dice, int target) {
    if(target < 0)  return 0;
    if(dice == 0 && target != 0)    return 0;
    if(target == 0 && dice != 0)    return 0;
    if(dice == 0 && target == 0)    return 1;
        
    long long ans = 0;
    for(int i = 1; i <= faces; i++)
        ans = ans + noOfWays(faces, dice - 1, target - i);
    return ans;
}
*/

/*
// Approach 2: Recurssion + Memoization
class Solution {
    long long solve(int faces, int dice, int target, vector<vector<long long>> &dp) {
        if(target < 0)  return 0;
        if(dice == 0 && target != 0)    return 0;
        if(target == 0 && dice != 0)    return 0;
        if(dice == 0 && target == 0)    return 1;
        if(dp[dice][target] != -1)  return dp[dice][target];
        
        long long ans = 0;
        for(int i = 1; i <= faces; i++)
            ans = ans + solve(faces, dice - 1, target - i, dp);
        dp[dice][target] = ans;
        return dp[dice][target];
    }
  public:
    long long noOfWays(int m, int n, int x) {
        vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, -1));
        return solve(m, n, x, dp);
    }
};
*/


/*
// Approach 3: Tabulation
long long noOfWays(int m, int n, int x) {
    vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
    dp[0][0] = 1;
    for(int dice = 1; dice <= n; dice++){
        for(int target = 1; target <= x; target++){
            long long ans = 0;
            for(int i = 1; i <= m; i++){
                if(target - i >= 0)
                    ans = ans + dp[dice - 1][target - i];
            }
            dp[dice][target] = ans;
        }
    }
    return dp[n][x];
}
*/


long long noOfWays(int m, int n, int x) {
    vector<long long> prev(x + 1, 0);
    vector<long long> curr(x + 1, 0);
    prev[0] = 1;
    for(int dice = 1; dice <= n; dice++){
        for(int target = 1; target <= x; target++){
            long long ans = 0;
            for(int i = 1; i <= m; i++){
                if(target - i >= 0)
                    ans = ans + prev[target - i];
            }
            curr[target] = ans;
        }
        prev = curr;
    }
    return prev[x];
}