// https://www.naukri.com/code360/problems/cut-into-segments_1214651
#include <bits/stdc++.h>
using namespace std;

/*
// Approach - 1: Recurssion
int solve(int n, int x, int y, int z) {
	if(n == 0)	return 0;
	if(n < 0)	return INT_MIN;
	int a = solve(n - x, x, y, z) + 1;
	int b = solve(n - y, x, y, z) + 1;
	int c = solve(n - z, x, y, z) + 1;
	return max(a, max(b, c));
}
int cutSegments(int n, int x, int y, int z) {
	int ans = solve(n, x, y, z);
	return ans < 0 ? 0 : ans;
}
*/

/*
// Approach - 2: Recurssion + Memoization
int solve(int n, int x, int y, int z, vector<int> &dp) {
	if(n == 0)	return 0;
	if(n < 0)	return INT_MIN;
	if(dp[n] != -1)	return dp[n];
	int a = solve(n - x, x, y, z, dp) + 1;
	int b = solve(n - y, x, y, z, dp) + 1;
	int c = solve(n - z, x, y, z, dp) + 1;
	dp[n] = max(a, max(b, c));
	return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n + 1, -1);
	int ans = solve(n, x, y, z, dp);
	return ans < 0 ? 0 : ans;
}
*/

// Approach - 3: Tabulation
int cutSegments(int n, int x, int y, int z) {
    vector <int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (i - x >= 0 && dp[i - x] != -1)	dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0 && dp[i - y] != -1)	dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0 && dp[i - z] != -1)	dp[i] = max(dp[i], dp[i - z] + 1);
    }

    return dp[n] == -1 ? 0 : dp[n];
}
