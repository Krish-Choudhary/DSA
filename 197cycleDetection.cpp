// https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670
#include <bits/stdc++.h>
using namespace std;

/*
// using BFS
bool isCyclicBFS(int source, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> adjList){
    
    unordered_map<int, int> parent;

    parent[source] = -1;
    visited[source] = true;

    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(int neighbour: adjList[front]){
            if(visited[neighbour] && parent[front] != neighbour)    return true;
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, vector<int>> adjList;
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for(int i = 0; i < n; i++){
        if(!visited[i]) if(isCyclicBFS(i, visited, adjList))    return "Yes";
    }
    return "No";
}

*/