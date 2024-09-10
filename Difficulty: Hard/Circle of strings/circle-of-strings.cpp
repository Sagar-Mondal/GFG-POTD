//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> adj[], int visited[]) {
        visited[node] = 1;
        for (auto u : adj[node]) {
            if (!visited[u])
                dfs(u, adj, visited);
        }
    }
    int isCircle(vector<string> &arr) {
        int N = arr.size();
        int i;
        vector<int> adj[26], adjr[26];
        for (i = 0; i < N; i++) {
            int x = arr[i].size() - 1;
            adj[(arr[i][0] - 'a')].emplace_back((arr[i][x] - 'a'));
            adjr[(arr[i][x] - 'a')].emplace_back((arr[i][0] - 'a'));
        }
        int indeg[26] = {0};
        for (i = 0; i < 26; i++) {
            if (adj[i].size() > 0) {
                for (auto u : adj[i])
                    indeg[u]++;
            }
        }
        for (i = 0; i < 26; i++) {
            if (adj[i].size() > 0 and indeg[i] != adj[i].size()) {
                return 0;
            }
        }
        int visited[26] = {0};
        for (i = 0; i < 26; i++) {
            if (indeg[i] > 0)
                break;
        }
        int n = i;
        dfs(n, adj, visited);
        for (i = 0; i < 26; i++) {
            if (adj[i].size() and !visited[i]) {
                return 0;
            }
        }
        for (i = 0; i < 26; i++)
            visited[i] = 0;
        dfs(n, adjr, visited);
        for (i = 0; i < 26; i++) {
            if (adjr[i].size() and !visited[i]) {
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends