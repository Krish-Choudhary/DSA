// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1
#include <bits/stdc++.h>
using namespace std;

/*
// Approach 1: Recurssion
class Solution{
private:
    bool solve(int N, int arr[], int target, int index){
        if(target == 0) return true;
        if(target < 0 || index >= N)  return false;
        
        bool include = solve(N, arr, target - arr[index], index + 1);
        bool exclude = solve(N, arr, target, index + 1);
        
        return include || exclude;
    }
public:
    int equalPartition(int N, int arr[]){
        int sum = 0;
        for(int i = 0; i < N; i++)    sum += arr[i];
        if(sum % 2 == 1)    return 0;
        return solve(N, arr, sum / 2, 0) ? 1 : 0;
    }
};
*/

/*
// Approach 2: Recurssion + Memoization
class Solution{
private:
    int solve(int N, int arr[], int target, int index, vector<vector<int>> &dp){
        if(target == 0) return 1;
        if(target < 0 || index >= N)  return 0;
        if(dp[target][index] != -1) return dp[target][index];
        
        int include = solve(N, arr, target - arr[index], index + 1, dp);
        int exclude = solve(N, arr, target, index + 1, dp);
        
        dp[target][index] = include || exclude;
        return dp[target][index];
    }
public:
    int equalPartition(int N, int arr[]){
        int sum = 0;
        for(int i = 0; i < N; i++)    sum += arr[i];
        if(sum % 2 == 1)    return 0;
        vector<vector<int>> dp(sum / 2 + 1, vector<int>(N, -1));
        return solve(N, arr, sum / 2, 0, dp);
    }
};
*/

/*
// Approach 3: Tabulation
class Solution{
private:
    int solve(int N, int arr[], int target){
        vector<vector<int>> dp(N + 1, vector<int>(target + 1, 0));
        for(int i = 0; i <= N; i++)  dp[i][0] = 1;
        
        for(int index = N - 1; index >= 0; index--){
            for(int tar = 0; tar <= target; tar++){
                int include = 0;
                if(tar - arr[index] >= 0)
                    include = dp[index + 1][tar - arr[index]];
                int exclude = dp[index + 1][tar];
                dp[index][tar] = include || exclude;
            }
        }
        return dp[0][target];
    }
public:
    int equalPartition(int N, int arr[]){
        int sum = 0;
        for(int i = 0; i < N; i++)    sum += arr[i];
        if(sum % 2 == 1)    return 0;
        return solve(N, arr, sum / 2);
    }
};
*/


class Solution{
private:
    int solve(int N, int arr[], int target){
        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);
        
        curr[0] = 1;
        next[0] = 1;
        
        
        for(int index = N - 1; index >= 0; index--){
            for(int tar = 0; tar <= target; tar++){
                int include = 0;
                if(tar - arr[index] >= 0)
                    include = next[tar - arr[index]];
                int exclude = next[tar];
                curr[tar] = include || exclude;
            }
            next = curr;
        }
        return curr[target];
    }
public:
    int equalPartition(int N, int arr[]){
        int sum = 0;
        for(int i = 0; i < N; i++)    sum += arr[i];
        if(sum % 2 == 1)    return 0;
        return solve(N, arr, sum / 2);
    }
};