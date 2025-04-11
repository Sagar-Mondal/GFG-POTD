//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<vector<vector<int>>> constructAdj(vector<vector<int>> &edges, int V) {

        // adj[u] = list of {v, wt}
        vector<vector<vector<int>>> adj(V);

        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        return adj;
    }
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        // Create adjacency list
        vector<vector<vector<int>>> adj = constructAdj(edges, V);

        // Create a priority queue to store vertices that
        // are being preprocessed.
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // Create a vector for distances and initialize all
        // distances as infinite
        vector<int> dist(V, INT_MAX);

        // Insert source itself in priority queue and initialize
        // its distance as 0.
        pq.push({0, src});
        dist[src] = 0;

        // Looping till priority queue becomes empty (or all
        // distances are not finalized)
        while (!pq.empty()) {

            // The first vertex in pair is the minimum distance
            // vertex, extract it from priority queue.
            int u = pq.top()[1];
            pq.pop();

            // Get all adjacent of u.
            for (auto x : adj[u]) {
                // Get vertex label and weight of current
                // adjacent of u.
                int v = x[0];
                int weight = x[1];

                // If there is shorter path to v through u.
                if (dist[v] > dist[u] + weight) {
                    // Updating distance of v
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Return the shortest distance array
        return dist;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends