//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCycleUtil(int v, vector<vector<int>>& adj, vector<bool>& visited,
                     int parent) {
        visited[v] = true;
        for (int i : adj[v]) {
            if (!visited[i]) {
                if (isCycleUtil(i, adj, visited, v))
                    return true;
            }
            else if (i != parent)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(V, false);
        for (int u = 0; u < V; u++) {
            if (!visited[u]) {
                if (isCycleUtil(u, adj, visited, -1))
                    return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends