// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(vector<int> base, vector<int> newBox){
        if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])    return true;
        return false;
    }
public:
    int maxHeight(vector<vector<int>>& a) {
        for(auto &arr: a) sort(arr.begin(), arr.end());
        int n = a.size();
        sort(a.begin(), a.end());
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        for(int currIndex = n - 1; currIndex >= 0; currIndex--){
            for(int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--){
                int include = 0;
                if(prevIndex == -1 || check(a[currIndex], a[prevIndex]))
                    include = a[currIndex][2] + next[currIndex + 1];
                int exclude = next[prevIndex + 1];
                curr[prevIndex + 1] = max(include, exclude);
            }
            next = curr;
        }
        return next[-1 + 1];
    }
};