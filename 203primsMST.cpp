// https://www.naukri.com/code360/problems/prim-s-mst_1095633
#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    // create adjList
    unordered_map<int, vector<pair<int, int>>> adjList;
    for(pair<pair<int, int>, int> edge: g){
        int u = edge.first.first;
        int v = edge.first.second;
        int weight = edge.second;
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    // nodes are starting from 1
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);
    key[1] = 0;

    for(int i = 1; i <= n; i++){
        int mini = INT_MAX;
        int u;

        // find min node
        for(int v = 1; v <= n; v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }

        // mark min node true
        mst[u] = true;

        // check its neighbours
        for(pair<int, int> neighbour: adjList[u]){
            int v = neighbour.first;
            int weight = neighbour.second;
            if(mst[v] == false && weight < key[v]){
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    // create ans
    vector<pair<pair<int, int>, int>> result;
    for(int i = 2; i <= n; i++){
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}
