// https://leetcode.com/problems/pizza-with-3n-slices/
#include <bits/stdc++.h>
using namespace std;


/*
// Approach 1: Recurssion
class Solution {
private:
    int solve(vector<int>& slices, int index, int n, int endIndex){
        if(n == 0 || index > endIndex)  return 0;
        int include = slices[index] + solve(slices, index + 2, n - 1, endIndex);
        int exclude = solve(slices, index + 1, n, endIndex);
        return max(include, exclude);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int case1 = solve(slices, 0, k / 3, k - 2);
        int case2 = solve(slices, 1, k / 3, k - 1);
        return max(case1, case2);
    }
};
*/


/*
// Approach 2: Recurssion + Memoization
class Solution {
private:
    int solve(vector<int>& slices, int index, int n, int endIndex, vector<vector<int>> &dp){
        if(n == 0 || index > endIndex)  return 0;
        if(dp[index][n] != -1)  return dp[index][n];
        int include = slices[index] + solve(slices, index + 2, n - 1, endIndex, dp);
        int exclude = solve(slices, index + 1, n, endIndex, dp);
        dp[index][n] = max(include, exclude);
        return dp[index][n];
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();

        vector<vector<int>> dp1(k, vector<int>(k / 3 + 1, -1));
        int case1 = solve(slices, 0, k / 3, k - 2, dp1);

        vector<vector<int>> dp2(k, vector<int>(k / 3 + 1, -1));
        int case2 = solve(slices, 1, k / 3, k - 1, dp2);
        
        return max(case1, case2);
    }
};
*/



/*
// Approach 3: Tabulation
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();

        vector<vector<int>> dp1(k + 2, vector<int>(k / 3 + 1, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(k / 3 + 1, 0));

        for(int index = k - 2; index >= 0; index--){
            for(int n = 1; n <= k / 3; n++){
                int include = slices[index] + dp1[index + 2][n - 1];
                int exclude = dp1[index + 1][n];
                dp1[index][n] = max(include, exclude);
            }
        }
        int case1 = dp1[0][k / 3];

        for(int index = k - 1; index >= 1; index--){
            for(int n = 1; n <= k / 3; n++){
                int include = slices[index] + dp2[index + 2][n - 1];
                int exclude = dp2[index + 1][n];
                dp2[index][n] = max(include, exclude);
            }
        }
        int case2 = dp2[1][k / 3];

        return max(case1, case2);
    }
};
*/

// Space optimisation
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();

        vector<int> prev1(k / 3 + 1, 0);
        vector<int> curr1(k / 3 + 1, 0);
        vector<int> next1(k / 3 + 1, 0);

        vector<int> prev2(k / 3 + 1, 0);
        vector<int> curr2(k / 3 + 1, 0);
        vector<int> next2(k / 3 + 1, 0);

        for(int index = k - 2; index >= 0; index--){
            for(int n = 1; n <= k / 3; n++){
                int include = slices[index] + next1[n - 1];
                int exclude = curr1[n];
                prev1[n] = max(include, exclude);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case1 = curr1[k / 3];

        for(int index = k - 1; index >= 1; index--){
            for(int n = 1; n <= k / 3; n++){
                int include = slices[index] + next2[n - 1];
                int exclude = curr2[n];
                prev2[n] = max(include, exclude);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = curr2[k / 3];

        return max(case1, case2);
    }
};