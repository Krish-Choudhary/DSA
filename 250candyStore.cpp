// https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1
#include <bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int N, int k){
    sort(candies, candies + N);
    int mini = 0;
    int buy = 0;
    int freee = N - 1;
        
    while(buy <= freee){
        mini += candies[buy];
        buy++;
        freee = freee - k;
    }
    int maxi = 0;
    buy = N - 1;
    freee = 0;
    while(buy >= freee){
        maxi += candies[buy];
        buy--;
        freee += k;
    }
    return {mini, maxi};
}