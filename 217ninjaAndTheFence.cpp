// https://www.naukri.com/code360/problems/ninja-and-the-fence_3210208
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int add(int a, int b){
    return ((a % MOD) + (b % MOD)) % MOD;
}

int mul(int a, int b){
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

// Approach - 1: Recurssion
/*
int solve(int n, int k){
    if(n == 1)  return k;
    if(n == 2)  return mul(k, k);
    int ans = add(mul(solve(n - 2, k), k - 1), mul(solve(n - 1, k), k - 1)) % MOD;
    return ans;
}

int numberOfWays(int n, int k) {
    return solve(n, k);
}
*/

/*
// Approach - 2: Recurssion + Memoization
int solve(int n, int k, vector<int> &dp){
    if(n == 1)  return k;
    if(n == 2)  return mul(k, k);
    if(dp[n] != -1) return dp[n];
    dp[n] = add(mul(solve(n - 2, k, dp), k - 1), mul(solve(n - 1, k, dp), k - 1)) % MOD;
    return dp[n];
}

int numberOfWays(int n, int k) {
    vector<int> dp(n + 1, -1);
    return solve(n, k, dp);
}
*/


/*
// Approach - 3: Tabulation
int numberOfWays(int n, int k) {
    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = mul(k, k);
    for(int i = 3; i <= n; i++){
        dp[i] = add(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
    }
    return dp[n];
}
*/


// Space optimisation
int numberOfWays(int n, int k) {
    int prev2 = k;
    int prev1 = mul(k, k);
    for(int i = 3; i <= n; i++){
        int ans = add(mul(prev2, k - 1), mul(prev1, k - 1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}