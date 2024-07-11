// https://www.naukri.com/code360/problems/count-derangements_873861
#include <bits/stdc++.h>
using namespace std;

/*
// Approach - 1: Recurssion
long long int countDerangements(int n) {
    if(n == 1)  return 0;
    if(n == 2)  return 1;

    long long int ans = (n - 1) * (countDerangements(n - 1) + countDerangements(n - 2));
    return ans % 1000000007;
}
*/

/*
// Approach - 2: Recurssion + Memoization
long long int solve(int n, vector<long long int> &dp){
    if(n == 1)  return 0;
    if(n == 2)  return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = (n - 1) * ((solve(n - 1, dp) % 1000000007) + (solve(n - 2, dp) % 1000000007)) % 1000000007;
    return dp[n];
}

long long int countDerangements(int n) {
    vector<long long int> dp(n + 1, -1);
    return solve(n, dp);
}
*/


/*
// Approach - 3: Tabulation
long long int countDerangements(int n) {
    vector<long long int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i <= n; i++){
        long long int first = dp[i - 1] % 1000000007;
        long long int second = dp[i - 2] % 1000000007;
        long long int sum = (first + second) % 1000000007;
        dp[i] = ((i - 1) * sum) % 1000000007;
    }
    return dp[n];
}
*/

// Space optimisation
long long int countDerangements(int n) {
    long long int prev2 = 0;
    long long int prev1 = 1;
    for(int i = 3; i <= n; i++){
        long long int first = prev1 % 1000000007;
        long long int second = prev2 % 1000000007;
        long long int sum = (first + second) % 1000000007;
        long long int ans = ((i - 1) * sum) % 1000000007;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}