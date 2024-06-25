// https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo,
	unordered_map<int, vector<int>> &adjList){
		visited[node] = true;

		for(int neighbour: adjList[node]){
			if(!visited[neighbour])	dfs(neighbour, visited, topo, adjList);
		}
		topo.push(node);
}

void revDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adjList){
	visited[node] = true;

	for(int neighbour: adjList[node]){
		if(!visited[neighbour])	revDFS(neighbour, visited, adjList);
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges){
	// create adjList
	unordered_map<int, vector<int>> adjList;
	unordered_map<int, vector<int>> transpose;
    for(vector<int> edge : edges) {
		int u = edge[0], v = edge[1];
        adjList[u].push_back(v);
		transpose[v].push_back(u);
    }

        stack<int> topo;
	unordered_map<int, bool> visited;
	// Topological sort
	for(int i = 0; i < v; i++){
		if(!visited[i])	dfs(i, visited, topo, adjList);
	}

	// Transpose graph, already created
	// Now do dfs
	// clear visited
	for(int i = 0; i < v; i++)	visited[i] = false;

	int count = 0;
	while(!topo.empty()){
		int top = topo.top();
		topo.pop();
		if(!visited[top]){
			count++;
			revDFS(top, visited, transpose);
		}
	}
	return count;
}