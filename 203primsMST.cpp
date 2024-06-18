// https://www.naukri.com/code360/problems/prim-s-mst_1095633
#include <bits/stdc++.h>
using namespace std;
// vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
//     // create adjList
//     unordered_map<int, vector<pair<int, int>>> adjList;
//     for(pair<pair<int, int>, int> edge: g){
//         int u = edge.first.first;
//         int v = edge.first.second;
//         int weight = edge.second;
//         adjList[u].push_back({v, weight});
//         adjList[v].push_back({u, weight});
//     }

//     // nodes are starting from 1
//     vector<int> key(n + 1, INT_MAX);
//     vector<bool> mst(n + 1, false);
//     vector<int> parent(n + 1, -1);
//     key[1] = 0;

//     for(int i = 1; i <= n; i++){
//         int mini = INT_MAX;
//         int u;

//         // find min node
//         for(int v = 1; v <= n; v++){
//             if(mst[v] == false && key[v] < mini){
//                 u = v;
//                 mini = key[v];
//             }
//         }

//         // mark min node true
//         mst[u] = true;

//         // check its neighbours
//         for(pair<int, int> neighbour: adjList[u]){
//             int v = neighbour.first;
//             int weight = neighbour.second;
//             if(mst[v] == false && weight < key[v]){
//                 parent[v] = u;
//                 key[v] = weight;
//             }
//         }
//     }

//     // create ans
//     vector<pair<pair<int, int>, int>> result;
//     for(int i = 2; i <= n; i++){
//         result.push_back({{parent[i], i}, key[i]});
//     }
//     return result;
// }
// TC = O(N^2)

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
	
	unordered_map<int, vector<pair<int, int>>> adjList;
    for(pair<pair<int, int>, int> edge: g){
        int u = edge.first.first - 1;
        int v = edge.first.second - 1;
        int weight = edge.second;
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

	// Min priority queue.
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// Taking source vertex as 0.
	int src = 0;

	vector<int> weight(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);
	// Insert source as in priority queue and initialize with 0.
	inMST[src] = true;

	// 0 weight for current source.
	pq.push(make_pair(0, src));

	// Weight from source to source.
	weight[src] = 0;

	while (!pq.empty())
	{
		// The first vertex int pair is the minimum weight vertex ,extract it from priority queue and node name is stored at the second of pair( it has to be done this way to keep the vertices sorted order with respect weight) weight must be first item in pair.
		int u = pq.top().second;
		pq.pop();

		// Include u to in our MST.
		inMST[u] = true;

		// Explore all adjacent of u and if not visited the relax them.
		for (auto x : adjList[u])
		{
			int v = x.first;
			int wt = x.second;

			// If v is not in mst and weight of (u,v) is smaller then the current weight of v.
			if (!inMST[v] && weight[v] > wt)
			{
				// Update weight of v.
				weight[v] = wt;

				// Insert it into the priority queue.
				pq.push(make_pair(weight[v], v));

				parent[v] = u;
			}
		}
	}


	vector<pair<pair<int, int>, int>> result;

	for(int i = 1; i < n; i++){
        result.push_back({{parent[i] + 1, i + 1}, weight[i]});
    }
	return result;
}
// TC = O(NlogN)