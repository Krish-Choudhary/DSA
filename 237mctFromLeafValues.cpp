// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
#include <bits/stdc++.h>
using namespace std;

/*
// Approach 1: Recurssion
class Solution {
private:
    int solve(vector<int>& arr, map<pair<int, int>, int> &maxi, int left, int right){
        if(left == right){  // leaf node
            return 0;
        }
        int ans = INT_MAX;
        for(int i = left; i < right; i++){
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i + 1, right));
        }
        return ans;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;      // maximum in range i -> j
        int n = arr.size();
        for(int i = 0; i < n; i++){
            maxi[{i, i}] = arr[i];
            for(int j = i + 1; j < n; j++)
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
        return solve(arr, maxi, 0, n - 1);
    }
};
*/


/*
// Approach 2: Recurssion + Memoization
class Solution {
private:
    int solve(vector<int>& arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp){
        if(left == right){  // leaf node
            return 0;
        }
        if(dp[left][right] != -1)   return dp[left][right];
        int ans = INT_MAX;
        for(int i = left; i < right; i++){
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solve(arr, maxi, left, i, dp) + solve(arr, maxi, i + 1, right, dp));
        }
        dp[left][right] = ans;
        return dp[left][right];
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;      // maximum in range i -> j
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for(int i = 0; i < n; i++){
            maxi[{i, i}] = arr[i];
            for(int j = i + 1; j < n; j++){
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }
        return solve(arr, maxi, 0, n - 1, dp);
    }
};
*/


/*
// Approach 3: Tabulation
int mctFromLeafValues(vector<int>& arr) {
    map<pair<int, int>, int> maxi;      // maximum in range i -> j
    int n = arr.size();
    for(int i = 0; i < n; i++){
        maxi[{i, i}] = arr[i];
        for(int j = i + 1; j < n; j++)
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int left = n - 1; left >= 0; left--){
        for(int right = 0; right < n; right++){
            if(left >= right)   continue;
            int ans = INT_MAX;
            for(int i = left; i < right; i++)
                ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + dp[left][i] + dp[i + 1][right]);
            dp[left][right] = ans;
        }
    }
    return dp[0][n - 1];
}
*/


// Approach 4: Optimal approach using stack

int mctFromLeafValues(vector<int>& arr) {
    int res = 0;
    vector<int> stack = {INT_MAX};
    for (int a : arr) {
        while (stack.back() <= a) {
            int mid = stack.back();
            stack.pop_back();
            res += mid*min(stack.back(), a);
        }
        stack.push_back(a);
    }
    for(int i=2 ; i<stack.size(); ++i)
        res += stack[i]*stack[i-1];
    return res;
}