// https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
#include <bits/stdc++.h>
using namespace std;

/*
// Approach - 1: Recurssion
class Solution
{
private:
    int solve(vector<vector<int>> mat, int i, int j, int &maxi)
    {
        if (i >= mat.size() || j >= mat[0].size())
            return 0;

        int right = solve(mat, i, j + 1, maxi);
        int diagonal = solve(mat, i + 1, j + 1, maxi);
        int down = solve(mat, i + 1, j, maxi);
        if (mat[i][j] == 1)
        {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else
            return 0;
    }

public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int maxi = 0;
        solve(mat, 0, 0, maxi);
        return maxi;
    }
};
*/



/*
// Approach - 2: Recurssion + Memoization
class Solution
{
private:
    int solve(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= mat.size() || j >= mat[0].size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(mat, i, j + 1, maxi, dp);
        int diagonal = solve(mat, i + 1, j + 1, maxi, dp);
        int down = solve(mat, i + 1, j, maxi, dp);
        if (mat[i][j] == 1)
        {
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
        }
        else
            dp[i][j] = 0;
        return dp[i][j];
    }

public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        solve(mat, 0, 0, maxi, dp);
        return maxi;
    }
};
*/



/*
// Approach - 3: Tabulation
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    int maxi = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int right = dp[i][j + 1];
            int diagonal = dp[i + 1][j + 1];
            int down = dp[i + 1][j];
            if (mat[i][j] == 1)
            {
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return maxi;
}
*/



/*
// Space optimisation from O(m*n) to O(m)
int maxSquare(int n, int m, vector<vector<int>> mat) {
    int maxi = 0;
    vector<int> curr(m + 1, 0);
    vector<int> next(m + 1, 0);
        
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            int right = curr[j + 1];
            int diagonal = next[j + 1];
            int down = next[j];
            if(mat[i][j] == 1){
                curr[j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, curr[j]);
            }
            else    curr[j] = 0;
        }
        next = curr;
    }
    return maxi;
}
*/



