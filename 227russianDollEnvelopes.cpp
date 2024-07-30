// https://leetcode.com/problems/russian-doll-envelopes/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort envelopes by width in ascending order. 
        // If two envelopes have the same width, sort by height in descending order.
        sort(envelopes.begin(), envelopes.end(), compare);

        // Extract the heights into a separate list.
        vector<int> heights;
        for (auto envelope : envelopes) {
            heights.push_back(envelope[1]);
        }

        vector<int> ans;

        for (int height : heights) {
            auto it = lower_bound(ans.begin(), ans.end(), height) - ans.begin();

            // If 'height' is greater than all elements in 'ans', append it.
            if (it == ans.size()) {
                ans.push_back(height);
            } 
            // Otherwise, replace the element at the found position with 'height'.
            else {
                ans[it] = height;
            }
        }
        return ans.size();
    }
};
