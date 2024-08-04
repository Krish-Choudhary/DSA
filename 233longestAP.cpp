// https://www.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1
#include <bits/stdc++.h>
using namespace std;

/*
// Approach 1: Recurssion
class Solution {
private:
    int solve(int index, int diff, vector<int> &arr, int n){
        // we are doing backward check
        // we can also do forward check
        if(index < 0)   return 0;
        
        int ans = 0;
        for(int j = index - 1; j >= 0; j--){
            if(arr[j] - arr[index] == diff){
                ans = max(ans, 1 + solve(j, diff, arr, n));
            }
        }
        return ans;
    }
public:
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2)  return n;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                ans = max(ans, 2 + solve(i, arr[i] - arr[j], arr, n));
            }
        }
        return ans;
    }
};
*/

/*
// Approach 2: Recurssion + Memoization
class Solution {
private:
    int solve(int index, int diff, vector<int> &arr, int n, unordered_map<int, int> dp[]){
        // we are doing backward check
        // we can also do forward check
        if(index < 0)   return 0;
        if(dp[index].count(diff))   return dp[index][diff];
        
        int ans = 0;
        for(int j = index - 1; j >= 0; j--){
            if(arr[j] - arr[index] == diff){
                ans = max(ans, 1 + solve(j, diff, arr, n, dp));
            }
        }
        dp[index][diff] = ans;
        return ans;
    }
public:
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2)  return n;
        unordered_map<int, int> dp[n + 1];
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                ans = max(ans, 2 + solve(i, arr[i] - arr[j], arr, n, dp));
            }
        }
        return ans;
    }
};
*/

/*
// Approach 3: Tabulation
int lengthOfLongestAP(vector<int>& arr) {
    int ans = 0;
    int n = arr.size();
    if(n <= 2)  return n;
    unordered_map<int, int> dp[n + 1];
        
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            int diff = arr[i] - arr[j];
            int count = 1;
            if(dp[j].count(diff))   count = dp[j][diff];
            dp[i][diff] = 1 + count;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}
*/



class Solution {
  public:
    // Function to find the length of the longest arithmetic progression in the given
    // array.
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        int ans =
            0; // Variable to store the length of the longest arithmetic progression
        int maxval = 0; // Variable to store the maximum value in the array

        // Finding the maximum value in the array
        for (int i = 0; i < n; i++) {
            maxval = max(arr[i], maxval);
        }

        // Creating a 2D vector to store the lengths of arithmetic progressions for
        // different differences
        vector<vector<int>> dp(2 * maxval + 1, vector<int>(n, 0));

        // Iterate through all pairs of elements to populate the dp array
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // Calculating the difference between the elements arr[i] and arr[j],
                // and adding maxval to ensure that the difference is positive
                int dif = arr[i] - arr[j] + maxval;

                // Storing the length of the arithmetic progression in dp[dif][i]
                dp[dif][i] = dp[dif][j] + 1;

                // Updating the length of the longest arithmetic progression if
                // dp[dif][i] is larger
                ans = max(ans, dp[dif][i]);
            }
        }

        // Returning the length of the longest arithmetic progression, adding 1 to
        // account for the initial element in the progression
        return ans + 1;
    }
};