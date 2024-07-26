// https://leetcode.com/problems/minimum-sideway-jumps/submissions/1332831192/
#include <bits/stdc++.h>
using namespace std;


/*
// Approach -1: Recurssion
class Solution {
private:
    int solve(vector<int>& obstacles, int currLane, int currPos, int n){
        if(currPos == n)    return 0;

        if(obstacles[currPos + 1] != currLane)  return solve(obstacles, currLane, currPos + 1, n);
        else{
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++){
                if(currLane != i && obstacles[currPos] != i)
                    ans = min(ans, 1 + solve(obstacles, i, currPos, n));
            }
            return ans;
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        return solve(obstacles, 2, 0, n);
    }
};
*/



/*
// Approach -2: Recurssion + Memoization
class Solution {
private:
    int solve(vector<int>& obstacles, int currLane, int currPos, int n, vector<vector<int>> &dp){
        if(currPos == n)    return 0;
        if(dp[currLane][currPos] != -1) return dp[currLane][currPos];
        if(obstacles[currPos + 1] != currLane)  dp[currLane][currPos] = solve(obstacles, currLane, currPos + 1, n, dp);
        else{
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++){
                if(currLane != i && obstacles[currPos] != i)
                    ans = min(ans, 1 + solve(obstacles, i, currPos, n, dp));
            }
            dp[currLane][currPos] = ans;
        }
        return dp[currLane][currPos];
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int> (n, -1));
        return solve(obstacles, 2, 0, n - 1, dp);
    }
};
*/


/*
// Approach -3: Tabulation
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, 0));

        // Traverse from second last point to the first point
        for (int i = n - 2; i >= 0; i--) {
            for (int lane = 1; lane <= 3; lane++) {
                if (obstacles[i + 1] != lane) {
                    dp[lane][i] = dp[lane][i + 1]; // No side jump needed, carry forward from next point
                } else {
                    int jumpToLane1 = INT_MAX, jumpToLane2 = INT_MAX;
                    if (lane == 1) {
                        if (obstacles[i] != 2) {
                            jumpToLane1 = min(jumpToLane1, 1 + dp[2][i + 1]);
                        }
                        if (obstacles[i] != 3) {
                            jumpToLane2 = min(jumpToLane2, 1 + dp[3][i + 1]);
                        }
                    } else if (lane == 2) {
                        if (obstacles[i] != 1) {
                            jumpToLane1 = min(jumpToLane1, 1 + dp[1][i + 1]);
                        }
                        if (obstacles[i] != 3) {
                            jumpToLane2 = min(jumpToLane2, 1 + dp[3][i + 1]);
                        }
                    } else { // lane == 3
                        if (obstacles[i] != 1) {
                            jumpToLane1 = min(jumpToLane1, 1 + dp[1][i + 1]);
                        }
                        if (obstacles[i] != 2) {
                            jumpToLane2 = min(jumpToLane2, 1 + dp[2][i + 1]);
                        }
                    }
                    dp[lane][i] = min(jumpToLane1, jumpToLane2);
                }
            }
        }
        return dp[2][0]; // Return the minimum side jumps needed to reach lane 2 at the start
    }
};
*/


class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<int> curr(4, 0); // Current minimum side jumps needed for each lane
        vector<int> nxt(4, 0);  // Next state of minimum side jumps

        // Traverse from second last point to the first point
        for (int i = obstacles.size() - 2; i >= 0; i--) {
            for (int lane = 1; lane <= 3; lane++) {
                if (obstacles[i + 1] != lane) {
                    curr[lane] = nxt[lane]; // No side jump needed, carry forward from next state
                } else {
                    int jumpToLane1 = INT_MAX, jumpToLane2 = INT_MAX;
                    if (lane == 1) {
                        if (obstacles[i] != 2) {
                            jumpToLane1 = min(jumpToLane1, 1 + nxt[2]);
                        }
                        if (obstacles[i] != 3) {
                            jumpToLane2 = min(jumpToLane2, 1 + nxt[3]);
                        }
                    } else if (lane == 2) {
                        if (obstacles[i] != 1) {
                            jumpToLane1 = min(jumpToLane1, 1 + nxt[1]);
                        }
                        if (obstacles[i] != 3) {
                            jumpToLane2 = min(jumpToLane2, 1 + nxt[3]);
                        }
                    } else { // lane == 3
                        if (obstacles[i] != 1) {
                            jumpToLane1 = min(jumpToLane1, 1 + nxt[1]);
                        }
                        if (obstacles[i] != 2) {
                            jumpToLane2 = min(jumpToLane2, 1 + nxt[2]);
                        }
                    }
                    curr[lane] = min(jumpToLane1, jumpToLane2);
                }
            }
            nxt = curr; // Update next state to current state for the next iteration
        }
        return curr[2]; // Return the minimum side jumps needed to reach lane 2 at the last point
    }
};