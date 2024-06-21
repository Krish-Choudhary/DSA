// https://www.naukri.com/code360/problems/bridges-in-graph_893026
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
        vector<vector<int>> &result, unordered_map<int, vector<int>> &adjList,
        unordered_map<int, bool> &visited){

    visited[node] = true;
    disc[node] = low[node] = timer++;
    // disc[node] = timer;
    // low[node] = timer;
    // timer++;

    for(int neighbour: adjList[node]){
        if(neighbour == parent) continue;
        if(!visited[neighbour]){
            dfs(neighbour, node, timer, disc, low, result, adjList, visited);
            low[node] = min(low[node], low[neighbour]);
            // check edge is bridge
            if(low[neighbour] > disc[node]){   // bridge present
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else{       // back edge
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, vector<int>> adjList;
    for(vector<int> edge: edges){
        int u = edge[0], v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    unordered_map<int, bool> visited;

    vector<vector<int>> result;
    // dfs
    for(int i = 0; i < v; i++){
        if(!visited[i]) dfs(i, parent, timer, disc, low, result, adjList, visited);
    }

    return result;
}