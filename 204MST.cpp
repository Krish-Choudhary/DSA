// https://www.naukri.com/code360/problems/minimum-spanning-tree_631769
#include <bits/stdc++.h>
using namespace std;

void makeSet(vector<int> &parent, vector<int> &rank, int n){
  for(int i = 0; i < n; i++){
    parent[i] = i;
    rank[i] = 0;
  }
}

int findParent(vector<int> &parent, int node){
  if(parent[node] == node)  return node;
  parent[node] = findParent(parent, parent[node]);    // path compression
  return parent[node];
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
  u = findParent(parent, u);
  v = findParent(parent, v);

  if(rank[u] < rank[v]) parent[u] = v;
  else if(parent[u] > parent[v])  parent[v] = u;
  else{
    parent[u] = v;
    rank[v]++;
  }
  
}

int minimumSpanningTree(vector<vector<int>>& edges, int n){
  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent, rank, n);
}