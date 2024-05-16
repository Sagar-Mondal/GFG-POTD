//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int dfs(vector<int>adj[], int u, int prt, int &ans) {
        int cnt=0;
        for(auto v : adj[u]) {
            if(v!=prt) {
                int x = dfs(adj, v, u, ans);
                if(x%2==0)
                    ans++;
                else
                    cnt+=x;
            }
        }
        return cnt+1;
    }
    
    int minimumEdgeRemove(int n, vector<vector<int>>edges){
        vector<int>adj[n];
        
        int sz = edges.size();
        for(int i=0; i<sz; ++i) {
            adj[edges[i][1]-1].push_back(edges[i][0]-1);
            adj[edges[i][0]-1].push_back(edges[i][1]-1);
        }
        
        int ans = 0;
        dfs(adj, 0, -1, ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends