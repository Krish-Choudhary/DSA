// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool compare(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int, int>> timings;
        for(int i = 0; i < n; i++)
            timings.push_back({start[i], end[i]});
        sort(timings.begin(), timings.end(), compare);
        int count = 1;  // 1st meeting done
        int ansEnd = timings[0].second;
        for(int i = 1; i < n; i++){
            if(timings[i].first > ansEnd){
                count++;
                ansEnd = timings[i].second;
            }
        }
        return count;
    }
};