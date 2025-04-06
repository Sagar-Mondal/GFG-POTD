//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void topoSortUtil(int v, vector<vector<int>>& adj, vector<bool>& visited,
                      stack<int>& st) {
        visited[v] = true;
        for (int i : adj[v]) {
            if (!visited[i])
                topoSortUtil(i, adj, visited, st);
        }
        st.push(v);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        stack<int> st;
        vector<bool> visited(V, false);
        vector<vector<int>> adj(V);

        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                topoSortUtil(i, adj, visited, st);
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        int x = V;
        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(x, res, adj);
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