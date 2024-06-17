// https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469
#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int, vector<pair<int, int>>> adjList;
    for(vector<int> edge: vec){
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    vector<int> distance(vertices, INT_MAX);
    set<pair<int, int>> st;

    distance[source] = 0;
    st.insert({0, source});

    while(!st.empty()){
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for(pair<int, int> neighbour: adjList[topNode]){
            if(nodeDistance + neighbour.second < distance[neighbour.first]){
                // new shorter path is found
                // check if any previous record in the set
                auto record = st.find({distance[neighbour.first], neighbour.first});
                // if record found then erase it
                if(record != st.end())  st.erase(record);

                // distance update
                distance[neighbour.first] = nodeDistance + neighbour.second;
                // new record in set
                st.insert({distance[neighbour.first], neighbour.first});
            }
        }
    }
    return distance;
}
