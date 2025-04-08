//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<vector<int>> &adj, int c, vector<bool> &visited) {
        visited[c] = true;
        for (auto i : adj[c]) {
            if (!visited[i])
                dfs(adj, i, visited);
        }
    }

    // Construct adjacency list without the edge (c, d)
    vector<vector<int>> constructadj(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {

            // Skip the edge (c, d) or (d, c)
            if ((edge[0] == c && edge[1] == d) || (edge[0] == d && edge[1] == c))
                continue;

            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }

    // Check if the edge (c, d) is a bridge
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adj = constructadj(V, edges, c, d);

        vector<bool> visited(V, false);
        dfs(adj, c, visited);

        // if d is not reachable from c ? bridge
        return !visited[d];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends