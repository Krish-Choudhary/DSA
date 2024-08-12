// https://www.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/0
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // Approach : Greedy algorithms
        
        // Edge case: If M > N, survival is impossible.
        if (M > N) return -1;

        // Step 1 : Find the total sundays which comes within our days to survie
        int sundays = S/7;

        // Step 2 : Declare some variables 
        int buyingDays = S - sundays; 
        int totalFoodReq = M * S; 
        int ans = 0; // minDaysRequired to survive
        
        // Step 3 : Find ans
        if(totalFoodReq % N == 0) {
            ans = totalFoodReq/N;
        }
        else {
            ans = totalFoodReq/N + 1;
        }
        
        // Step 4 : Handle edge case
        // Cannot buy if our ans has more days than buying days
        if (ans > buyingDays) {
            // If the days needed to buy food exceed the available buying days, return -1.
            return -1;
        }
        
        // Step 5 : Additional check: Simulate buying and consuming the food day by day.
        int foodAvailable = 0;
        
        for (int i = 1; i <= S; i++) {
            // Every 7th day is a Sunday (no buying).
            if (i % 7 != 0) {
                // Buy food N on non-Sundays.
                foodAvailable = foodAvailable + N;
            }
            
            // Consume food M.
            foodAvailable = foodAvailable - M;
            
            // If food falls below 0 on any day, return -1.
            // This means unsufficient food was there on current day
            // hence cant survive.
            if (foodAvailable < 0) {
                return -1;
            }
        }
        
        // If all checks are passed, return the minimum days required.
        return ans;

    }
};