/*
Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int node = it.second;

            if (d > dist[node]) continue;

            for (auto &nbr : adj[node]) {
                int adjNode = nbr.first;
                int wt = nbr.second;

                if (dist[node] + wt < dist[adjNode]) {
                    dist[adjNode] = dist[node] + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        vector<int> ans;
        for (int i = 1; i <= n; i++) ans.push_back(dist[i]);
        return ans;
    }
};