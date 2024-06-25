// https://www.naukri.com/code360/problems/bellmon-ford_2041977
#include <bits/stdc++.h>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> distance(n + 1, 1e8);
    distance[src] = 0;
    for(int i = 1; i < n; i++){
        // traverse on edge list
        for(int j = 0; j < m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
            }
        }
    }
    // it is already given that graph doesn't contain -ve cycle
    return distance;
    // bool flag = false;
    // for(int j = 0; j < m; j++){
    //     int u = edges[j][0];
    //     int v = edges[j][1];
    //     int wt = edges[j][2];

    //     if(distance[u] != INT_MAX && distance[u] + wt < distance[v]){
    //         flag = true;
    //     }
    // }
    // if(flag){   // negative cycle present
    //     return -1;
    // }
    // return distance;
}