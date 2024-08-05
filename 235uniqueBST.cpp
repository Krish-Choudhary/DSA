// https://leetcode.com/problems/unique-binary-search-trees/
#include <bits/stdc++.h>
using namespace std;

/*
// Approach 1: Recurssion
int numTrees(int n) {
    if(n <= 1)  return 1;
    int ans = 0;
    for(int i = 1; i <= n; i++){    // root nodes
        ans += numTrees(i - 1) * numTrees(n - i);
    }
    return ans;
}
*/


/*
// Approach 2: Recurssion + Memoization
class Solution {
private:
    int solve(int n, vector<int> &dp) {
        if(n <= 1)  return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i = 1; i <= n; i++){    // root nodes
            ans += solve(i - 1, dp) * solve(n - i, dp);
        }
        dp[n] = ans;
        return dp[n];
    }
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
*/


/*
// Approach 3: Tabulation
int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){    // no of nodes
        for(int j = 1; j <= i; j++){    // root
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}
*/



/*
// Catalan numbers

*/