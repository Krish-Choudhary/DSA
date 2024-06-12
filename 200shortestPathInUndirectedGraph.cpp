// https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297

#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int, vector<int>> adjList;
    for(auto edge : edges){
		int u = edge.first;
		int v = edge.second;
    	adjList[u].push_back(v);
		adjList[v].push_back(u);
    }

	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;

	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(int neighbour: adjList[front]){
			if(!visited[neighbour]){
				visited[neighbour] = true;
				parent[neighbour] = front;
				q.push(neighbour);
			}
		}
	}
	// parent is ready

	// preparing shortest path
	vector<int> ans;
	int currNode = t;
	ans.push_back(t);
	while(currNode != s){
		currNode = parent[currNode];
		ans.push_back(currNode);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
