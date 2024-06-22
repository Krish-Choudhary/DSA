#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &disc, vector<int> &low, 
    unordered_map<int, bool> &visited, unordered_map<int, vector<int>> adjList, 
    vector<int> &articulationPoint, int &timer){
        
        visited[node] = true;
        disc[node] = low[node] = timer++;
        int child = 0;
        for(int neighbour: adjList[node]){
            if(neighbour == parent) continue;
            if(!visited[neighbour]){
                dfs(neighbour, node, disc, low, visited, adjList, articulationPoint, timer);
                low[node] = min(low[node], low[neighbour]);
                // check AP or not
                if((low[neighbour] >= disc[node]) && parent != -1){
                    articulationPoint[node] = node;
                }
                child++;
            }
            else{       // backedge
                low[node] = min(low[node], disc[neighbour]);
            }
        }
        if(parent == -1 && child > 1)   articulationPoint[node] = node;
}

int main(){
    int n = 5, e = 5;
    vector<pair<int, int>> edges;
    edges.push_back({0, 3});
    edges.push_back({3, 4});
    edges.push_back({0, 4});
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    unordered_map<int, vector<int>> adjList;
    for(pair<int, int> edge: edges){
        int u = edge.first, v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    unordered_map<int, bool> visited;
    vector<int> articulationPoint(n, -1);

    for(int i = 0; i < n; i++){
        if(!visited[i])     dfs(i, -1, disc, low, visited, adjList, articulationPoint, timer);
    }

    cout << "Articulation points: ";
    for(int i : articulationPoint)  if(i != -1)  cout << i << " ";

    return 0;
}