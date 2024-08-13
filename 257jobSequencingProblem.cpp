// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
#include <bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution{
    private:
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n){ 
        sort(arr, arr + n, cmp);
        int maxDeadline = INT_MIN;
        for(int i = 0; i < n; i++)  maxDeadline = max(maxDeadline, arr[i].dead);
        vector<int> schedule(maxDeadline + 1, -1);  // 1 base indexing
        int count = 0, maxProfit = 0;
        for(int i = 0; i < n; i++){
            int currProfit = arr[i].profit;
            int jobID = arr[i].id;
            int deadline = arr[i].dead;
            for(int k = deadline; k > 0; k--){
                if(schedule[k] == -1){
                    maxProfit += currProfit;
                    schedule[k] = jobID;
                    count++;
                    break;
                }
            }
        }
        return {count, maxProfit};
    } 
};