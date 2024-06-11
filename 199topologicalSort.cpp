// https://www.naukri.com/code360/problems/topological-sort_982938
#include <bits/stdc++.h> 
using namespace std;
void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, vector<int>> &adjList){
    visited[node] = true;

    for(int neighbour: adjList[node]){
        if(!visited[neighbour]) topoSort(neighbour, visited, s, adjList);
    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, vector<int>> adjList;
    for(auto i: edges)  adjList[i[0]].push_back(i[1]);

    vector<bool> visited(v, false);
    stack<int> s;

    for(int i = 0; i < v; i++){
        if(!visited[i]) topoSort(i, visited, s, adjList);
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
