// https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/0
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    static bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
        return a.second.second < b.second.second;
    }
    vector<int> maxMeetings(int n,vector<int> &start,vector<int> &end){
        vector<pair<int, pair<int, int>>> timings;
        for(int i = 0; i < n; i++)
            timings.push_back({i, {start[i], end[i]}});
        sort(timings.begin(), timings.end(), compare);
        vector<int> ans;
        ans.push_back(timings[0].first + 1);    // first meeting done
        int ansEnd = timings[0].second.second;
        for(int i = 1; i < n; i++){
            if(timings[i].second.first > ansEnd){
                ans.push_back(timings[i].first + 1);
                ansEnd = timings[i].second.second;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};