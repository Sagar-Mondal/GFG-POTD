//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node, vector<bool>&vis, vector<int>&temp, unordered_map<int, list<int>>&adj){
        vis[node]=true;
        temp.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,temp,adj);
            }
        }
    }
    int findNumberOfGoodComponent(int e, int n, vector<vector<int>> &edges) {
        unordered_map<int, list<int>>adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt=0;
        vector<bool>vis(n+1);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vector<int>temp;
                dfs(i,vis,temp,adj);
                bool flag= true;
                for(auto it:temp){
                    if((adj[it].size()+1)!=temp.size()){
                        flag=false;
                    }
                }
                if(flag){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends