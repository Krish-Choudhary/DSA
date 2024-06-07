#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph{
    public:
    unordered_map<T, vector<T>> adjList;

    void addEdge(T u, T v, bool directed = true){
        adjList[u].push_back(v);
        if(!directed)   adjList[v].push_back(u);
    }

    void printAdjList(){
        for(auto i: adjList){
            cout << i.first << " -> ";
            for(auto j: i.second){
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    graph<int> g;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u,v, false);
    }
    g.printAdjList();
    return 0;
}