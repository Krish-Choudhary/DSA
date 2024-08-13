// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(), a.end());
    int i = 0, j = m - 1;
    int mini = INT_MAX;
    while(j < n){
        int diff = a[j] - a[i];
        mini = min(mini, diff);
        i++;
        j++;
    }
    return mini;
}