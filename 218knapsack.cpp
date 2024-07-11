// https://www.naukri.com/code360/problems/0-1-knapsack_920542
#include <bits/stdc++.h>
using namespace std;

/*
// Approach - 1: Recurssion
int solve(vector<int> &weight, vector<int> &value, int index, int capacity) 
{
	// if last element to steal, we will obviously steal it if we have capacity
	if(index == 0){
		if(weight[0] <= capacity)	return value[0];
		else	return 0;
	}

	int include = 0;
	if(weight[index] <= capacity)
		include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
	int exclude = solve(weight, value, index - 1, capacity);
	return max(include, exclude);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight, value, n - 1, maxWeight);
}
*/


/*
// Approach - 2: Recurssion + Memoization
int solve(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp) 
{
	// if last element to steal, we will obviously steal it if we have capacity
	if(index == 0){
		if(weight[0] <= capacity)	return value[0];
		else	return 0;
	}

	if(dp[index][capacity] != -1)	return dp[index][capacity];

	int include = 0;
	if(weight[index] <= capacity)
		include = value[index] + solve(weight, value, index - 1, capacity - weight[index], dp);
	int exclude = solve(weight, value, index - 1, capacity, dp);
	dp[index][capacity] = max(include, exclude);
	return dp[index][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
	return solve(weight, value, n - 1, maxWeight, dp);
}
*/


/*
// Approach - 3: Tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

	// base case
	for(int w = weight[0]; w <= maxWeight; w++){
		if(weight[0] <= maxWeight)	dp[0][w] = value[0];
		else	dp[0][w] = 0;
	}

	for(int index = 1; index < n; index++){
		for(int w = 0; w <= maxWeight; w++){
			int include = 0;
			if(weight[index] <= w)
				include = value[index] + dp[index - 1][w - weight[index]];
			int exclude = dp[index - 1][w];
			dp[index][w] = max(include, exclude);
		}
	}
	
	return dp[n - 1][maxWeight];
}
*/




/*
// Space optimisation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> curr(maxWeight + 1, 0);
	vector<int> prev(maxWeight + 1, 0);

	// base case
	for(int w = weight[0]; w <= maxWeight; w++){
		if(weight[0] <= maxWeight)	prev[w] = value[0];
		else	prev[w] = 0;
	}

	for(int index = 1; index < n; index++){
		for(int w = 0; w <= maxWeight; w++){
			int include = 0;
			if(weight[index] <= w)
				include = value[index] + prev[w - weight[index]];
			int exclude = prev[w];
			curr[w] = max(include, exclude);
		}
		prev = curr;
	}

	return prev[maxWeight];
}
*/



// More space optimisation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> curr(maxWeight + 1, 0);

	// base case
	for(int w = weight[0]; w <= maxWeight; w++){
		if(weight[0] <= maxWeight)	curr[w] = value[0];
		else	curr[w] = 0;
	}

	for(int index = 1; index < n; index++){
		for(int w = maxWeight; w >= 0; w--){
			int include = 0;
			if(weight[index] <= w)
				include = value[index] + curr[w - weight[index]];
			int exclude = curr[w];
			curr[w] = max(include, exclude);
		}
	}

	return curr[maxWeight];
}