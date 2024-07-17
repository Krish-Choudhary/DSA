// https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1
#include <bits/stdc++.h>
using namespace std;

/*
Approach - 1: Recurssion
int MinSquares(int n){
	    if(n == 0)  return 0;
	    int ans = n;
	    for(int i = 1; i * i <= n; i++){
	        ans = min(ans, 1 + MinSquares(n - (i * i)));
	    }
	    return ans;
	}
*/


/*
// Approach - 2: Recurssion + Memoization
class Solution{
    private:
    int solve(int n, vector<int> &dp){
        if(n == 0)  return 0;
        if(dp[n] != -1) return dp[n];
	    int ans = n;
	    for(int i = 1; i * i <= n; i++){
	        ans = min(ans, 1 + solve(n - (i * i), dp));
	    }
	    dp[n] = ans;
	    return dp[n];
    }
	public:
	int MinSquares(int n){
	    vector<int> dp(n + 1, -1);
	    return solve(n, dp);
	}
};
*/

/*
// Approach - 3: Tabulation
int MinSquares(int n){
	    vector<int> dp(n + 1, n);
	    dp[0] = 0;
	    for(int i = 1; i <= n; i++){
	        for(int j = 1; j * j <= n; j++){
	            if((i - (j * j)) >= 0)
	                dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
	        }
	    }
	    return dp[n];
	}
*/