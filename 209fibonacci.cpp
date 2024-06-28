#include<bits/stdc++.h>
using namespace std;
/*
// Top down approach
int fib(int n, vector<int> &dp){
        if(n == 1 || n == 2)    return 1;
        
        if(dp[n] != -1) return dp[n];

        dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
        return dp[n];
}

int main()
{
        int n;
        cin >> n;
        vector<int> dp(n + 1, -1);
        cout << fib(n, dp) << endl;
        return 0;
}
*/

/*
// Bottom up approach
int main(){
        int n;
        cin >> n;
        vector<int> dp(n + 1, -1);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; i++)     dp[i] = dp[i - 2] + dp[i - 1];
        cout << dp[n] << endl;
        return 0;
}
*/

// Space optimisation
int main()
{
        int n;
        cin >> n;
        int prev1, prev2;
        prev1 = 1;
        prev2 = 1;
        for(int i = 3; i <= n; i++){
                int curr = prev1 + prev2;
                prev2 = prev1;
                prev1 = curr;
        }
        cout << prev1 << endl;
        return 0;
}