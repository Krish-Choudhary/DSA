// https://www.naukri.com/code360/problems/minimum-elements_3843091
#include <bits/stdc++.h>
using namespace std;
/*
// Approach - 1: Recurrsion
int solveByRecurssion(vector<int> &num, int x){
    if(x == 0)  return 0;
    if(x < 0)   return INT_MAX;

    int mini = INT_MAX;
    for(int number: num){
        int ans = solveByRecurssion(num, x - number);
        if(ans != INT_MAX)  mini = min(mini, 1 + ans);  // consider current coin
    }
    return mini;
}

int minimumElements(vector<int> &num, int x){
    int ans = solveByRecurssion(num, x);
    return ans == INT_MAX ? -1 : ans;
}
*/



/*
// Approach - 2: Recurssion + Memoization
int solveByMemoization(vector<int> &num, int x, vector<int> &dp){
    if(x == 0)  return 0;
    if(x < 0)   return INT_MAX;
    if(dp[x] != -1) return dp[x];
    int mini = INT_MAX;
    for(int number: num){
        int ans = solveByMemoization(num, x - number, dp);
        if(ans != INT_MAX)  mini = min(mini, 1 + ans);  // consider current coin
    }
    dp[x] = mini;
    return dp[x];
}

int minimumElements(vector<int> &num, int x){
    vector<int> dp(x + 1, -1);
    int ans = solveByMemoization(num, x, dp);
    return ans == INT_MAX ? -1 : ans;
}
*/

// Approach - 3: Tabuation
int minimumElements(vector<int> &num, int x){
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int number: num){
            if (i - number >= 0 && dp[i - number] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - number]);
        }
    }
    return dp[x] == INT_MAX ? -1 : dp[x];
}