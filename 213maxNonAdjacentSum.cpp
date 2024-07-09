// https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261
#include <bits/stdc++.h>
using namespace std;

/*
// Approach - 1: Recurssion
int solve(vector<int> nums, int index){
    if(index < 0)   return 0;
    if(index == 0)  return nums[0];
    int include = solve(nums, index - 2) + nums[index];
    int exclude = solve(nums, index - 1);
    return max(include, exclude);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    return solve(nums, n - 1);
}
*/


/*
// Approach - 2: Recurssion + Memoization
int solve(vector<int> nums, int index, vector<int> &dp){
    if(index < 0)   return 0;
    if(index == 0)  return nums[0];
    if(dp[index] != -1) return dp[index];
    int include = solve(nums, index - 2, dp) + nums[index];
    int exclude = solve(nums, index - 1, dp);
    dp[index] = max(include, exclude);
    return dp[index];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(nums, n - 1, dp);
}
*/

/*
// Approach - 3: Tabulation
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for(int i = 1; i < n; i++){
        int include = dp[i - 2] + nums[i];
        int exclude = dp[i - 1];
        dp[i] = max(include, exclude);
    }
    return dp[n - 1];
}
*/

// Space optimisation
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev1 = nums[0], prev2 = 0;
    for(int i = 1; i < n; i++){
        int include = prev2 + nums[i];
        int exclude = prev1;
        prev2 = prev1;
        prev1 = max(include, exclude);
    }
    return prev1;
}