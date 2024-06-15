#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int, vector<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight){
        adjList[u].push_back(make_pair(v, weight));
    }

    void printAdjList(){
        for(auto i: adjList){
            cout << i.first << " -> ";
            for(auto j: i.second){
                cout << "[" << j.first << ", " << j.second << "] ";
            }
            cout << endl;
        }
    }

    void dfs(int node, vector<bool> &visited, stack<int> &s){
        visited[node] = true;
        for(auto neighbour: adjList[node]){
            if(!visited[neighbour.first])   dfs(neighbour.first, visited, s);
        }
        s.push(node);
    }

    void getShortestPath(int source, vector<int> &distance, stack<int> &topologicalSort){
        distance[source] = 0;
    
        while(!topologicalSort.empty()){
            int top = topologicalSort.top();
            topologicalSort.pop();
            if(distance[top] != INT_MAX){
                for(auto i: adjList[top]){
                    if(distance[top] + i.second < distance[i.first])
                        distance[i.first] = distance[top] + i.second;
                }
            }
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdjList();

    int n = 6;
    vector<bool> visited(n, false);
    stack<int> s;
    for(int i = 0; i < n; i++){
        if(!visited[i]) g.dfs(i, visited, s);
    }

    int source = 1;
    vector<int> distance(n, INT_MAX);
    g.getShortestPath(source, distance, s);

    for(int i = 0; i < n; i++)  cout << distance[i] << " ";
    return 0;
}