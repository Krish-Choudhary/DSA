// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
#include <bits/stdc++.h>
using namespace std;

/*
// Approach 1: Recurssion
class Solution {
private:
    int solve(vector<int>& nums1, vector<int>& nums2, int n, int index, bool prevSwapped){
        if(index == n)  return 0;

        int ans = INT_MAX;
        int prev1 = nums1[index - 1], prev2 = nums2[index - 1];
        if(prevSwapped) swap(prev1, prev2);     // as we are not swapping in the real array

        // no swap
        if(nums1[index] > prev1 && nums2[index] > prev2)    ans = solve(nums1, nums2, n, index + 1, false);
        // swap
        if(nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, n, index + 1, true));

        return ans;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        bool prevSwapped = false;
        int n = nums1.size();
        return solve(nums1, nums2, n, 1, prevSwapped);
    }
};
*/


/*
// Approach 2: Recurssion + Memoization
class Solution {
private:
    int solve(vector<int>& nums1, vector<int>& nums2, int n, int index, bool prevSwapped, vector<vector<int>> &dp){
        if(index == n)  return 0;
        if(dp[index][prevSwapped] != -1)    return dp[index][prevSwapped];

        int ans = INT_MAX;
        int prev1 = nums1[index - 1], prev2 = nums2[index - 1];
        if(prevSwapped) swap(prev1, prev2);     // as we are not swapping in the real array

        // no swap
        if(nums1[index] > prev1 && nums2[index] > prev2)    ans = solve(nums1, nums2, n, index + 1, 0, dp);
        // swap
        if(nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, n, index + 1, 1, dp));

        dp[index][prevSwapped] = ans;
        return dp[index][prevSwapped];
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        bool prevSwapped = false;
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(nums1, nums2, n, 1, prevSwapped, dp);
    }
};
*/


/*
// Approach 3: Tabulation
int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    int n = nums1.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for(int index = n - 1; index >= 1; index--){
        for(int swapped = 1; swapped >= 0; swapped--){
            int ans = INT_MAX;
            int prev1 = nums1[index - 1], prev2 = nums2[index - 1];
            if(swapped) swap(prev1, prev2);     // as we are not swapping in the real array

            // no swap
            if(nums1[index] > prev1 && nums2[index] > prev2)    ans = dp[index + 1][0];
            // swap
            if(nums1[index] > prev2 && nums2[index] > prev1)
                ans = min(ans, 1 + dp[index + 1][1]);

            dp[index][swapped] = ans;
        }
    }
    return dp[1][0];
}
*/

// TC = O(N)
// SC = O(1)
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size();
        vector<int> next(2, 0);
        vector<int> curr(2, 0);

        for(int index = n - 1; index >= 1; index--){
            for(int swapped = 1; swapped >= 0; swapped--){
                int ans = INT_MAX;
                int prev1 = nums1[index - 1], prev2 = nums2[index - 1];
                if(swapped) swap(prev1, prev2);     // as we are not swapping in the real array

                // no swap
                if(nums1[index] > prev1 && nums2[index] > prev2)    ans = next[0];
                // swap
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + next[1]);

                curr[swapped] = ans;
            }
            next = curr;
        }
        return next[0];
    }
};