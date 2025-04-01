//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfsRec(int i, vector<vector<int>>& adj, int V, vector<bool>& vis,
                vector<int>& res) {
        if (vis[i])
            return;

        // marking vertex as visited and adding it to output list.
        vis[i] = true;
        res.push_back(i);

        // iterating over connected components of the vertex and if any
        // of them is not visited then calling the function recursively.
        for (int j : adj[i]) {
            if (!vis[j])
                dfsRec(j, adj, V, vis, res);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();

        // using a boolean list to mark all the vertices as not visited.
        // Initialize all vertices as not visited.
        vector<bool> vis(V, false);

        vector<int> res;
        for (int i = 0; i < V; i++) {
            // if any vertex isn't visited then calling the function.
            if (!vis[i]) {
                dfsRec(i, adj, V, vis, res);
            }
        }
        // returning the output list.
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends