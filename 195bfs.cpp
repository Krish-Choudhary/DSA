// https://www.naukri.com/code360/problems/bfs-in-graph_973002
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto i: adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    unordered_map<int, bool> visited;

    // for disconnected graph
    // for(int i = 0; i < n; i++){
    //     if(!visited[i]) bfs(adj, visited, ans, i);
    // }
    // In this question we just need to print connected graph
    bfs(adj, visited, ans, 0);
    return ans;
}

/*
A better way for connected graph
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
  vector<int> bfsOutput;
  map<int, bool> visited;
  queue<int> que;
  que.push(0);
  visited[0] = true;
  while(!que.empty()){
    int front = que.front();
    que.pop();
    bfsOutput.push_back(front);
    for(auto i:adj[front]){
      if(!visited[i]){
        que.push(i);
        visited[i] = true;
      }
    }
  }
  return bfsOutput;
}
*/