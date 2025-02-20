// EXERCISE: 19

// You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.
// Constraint:
// 1<=adj.size()<=104
// 0<=edges<=adj.size()-1

// Solution

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> shortestPath(int n, vector<vector<int>> &adj, int src) {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return dist;
}

int main() {
    int n, m, src;
    cin >> n >> m >> src;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> result = shortestPath(n, adj, src);
    for (int x : result) cout << x << " ";
    return 0;
}
