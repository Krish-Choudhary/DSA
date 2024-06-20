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

bool cmp(vector<int> &a, vector<int> &b){
  return a[2] < b[2];
}

int minimumSpanningTree(vector<vector<int>>& edges, int n){
  // create disjoint set
  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent, rank, n);

  // sort edges
  sort(edges.begin(), edges.end(), cmp);

  int m = edges.size();
  int minWeight = 0;

  for(int i = 0; i < m; i++){
    int u = findParent(parent, edges[i][0]);
    int v = findParent(parent, edges[i][1]);

    if(u != v){
      unionSet(u, v, parent, rank);
      minWeight += edges[i][2];
    }
  }

  return minWeight;
}