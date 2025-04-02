//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<bool> vis(V, false);
        int s = 0;
        vis[s] = true;
        vector<int> res;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for (int x : adj[curr]) {
                if (!vis[x]) {
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
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
        // Use vector of vectors instead of array of vectors.
        vector<vector<int>> adj(V);

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
        vector<int> ans = obj.bfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends