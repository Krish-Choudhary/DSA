#include <bits/stdc++.h>
using namespace std;
/*
bool checkCycleDFS(int node, map<int, bool> &visited, map<int, bool> &dfsVisited, map<int, vector<int>> &adjList){
  visited[node] = true;
  dfsVisited[node] = true;

  for(int neighbour: adjList[node]){
    if(!visited[neighbour]){
      bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adjList);
      if(cycleDetected) return true;
    }
    else if(dfsVisited[neighbour]){
      // visited true
      return true;
    }
  }
  dfsVisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  map<int, vector<int>> adjList;
  int m = edges.size();

  for(int i = 0; i < m; i++){
    int u = edges[i].first;
    int v = edges[i].second;
    adjList[u].push_back(v);
  }

  map<int, bool> visited;
  map<int, bool> dfsVisited;
  
  for(int i = 1; i <= n; i++){
    if(!visited[i])
      if(checkCycleDFS(i, visited, dfsVisited, adjList))
        return 1;
  }
  return 0;
}
*/

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<vector<int>> adjList(n);
    int m = edges.size();
    for(int i = 0; i < m; i++){
      int u = edges[i].first - 1;     // -1 to make it 0 based indexing
      int v = edges[i].second - 1;
      adjList[u].push_back(v);
    }

    vector<int> inDegree(n, 0);
    for(vector<int> i: adjList){
        for(int j: i)   inDegree[j]++;
    }
    
    // 0 indegree
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0)  q.push(i);
    }

    int count = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        count++;

        // neighbour indegree update
        for(int neighbour: adjList[front]){
            inDegree[neighbour]--;
            if(inDegree[neighbour] == 0)    q.push(neighbour);
        }
    }
    return !(count == n);
}