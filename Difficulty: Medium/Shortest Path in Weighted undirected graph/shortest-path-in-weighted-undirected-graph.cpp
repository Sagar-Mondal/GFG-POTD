//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> parent(n + 1);
        set<pair<int, pair<int, int>>> st;
        st.insert({0, {1, 1}});
        vector<int> vis(n + 1);
        vector<vector<vector<int>>> adj(n + 1);
        for (auto i : edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        int temp = -1;
        while (!st.empty()) {
            int d = st.begin()->first;
            int p = st.begin()->second.first;
            int par = st.begin()->second.second;
            st.erase(st.begin());
            if (vis[p] == 1)
                continue;
            parent[p] = par;
            if (p == n) {
                temp = d;
                break;
            }
            vis[p] = 1;
            for (auto j : adj[p]) {
                st.insert({j[1] + d, {j[0], p}});
            }
        }
        if (temp == -1)
            return {-1};
        int p = n;
        while (p != 1) {
            ans.push_back(p);
            p = parent[p];
        }
        ans.push_back(1);
        ans.push_back(temp);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends