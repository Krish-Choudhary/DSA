// https://www.naukri.com/code360/problems/maximum-frequency-number_920319
#include <bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> mp;
    int max = -1;
    for(int i: arr){
        mp[i]++;
        if(mp[i] > max){
            max = mp[i];
        }
    }
    for(int i: arr){
        if(mp[i] == max)    return i;
    }
}