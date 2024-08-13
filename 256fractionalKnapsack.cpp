// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution {
    static bool cmp(pair<double, Item> a, pair<double, Item> b){
        return a.first > b.first;
    }
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        vector<pair<double, Item>> valuePerWeight;
        for(int i = 0; i < n; i++){
            double perUnitValue = (1.0 * arr[i].value) / (1.0 * arr[i].weight);
            valuePerWeight.push_back({perUnitValue, arr[i]});
        }
        sort(valuePerWeight.begin(), valuePerWeight.end(), cmp);
        double ans = 0;
        for(int i = 0; i < n; i++){
            if(valuePerWeight[i].second.weight > w){
                ans += w * valuePerWeight[i].first;
                w = 0;
                break;
            }
            else{
                ans += valuePerWeight[i].second.value;
                w -= valuePerWeight[i].second.weight;
            }
        }
        return ans;
    }
};