//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
  bool isCycle(int src, vector<int> &visited, vector<int> adj[]) {
        queue<pair<int,int>>q;
        q.push({src,-1});
        visited[src] = 1;
        
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto i : adj[node]) {
                if(!visited[i]) {
                    visited[i] = 1;
                    q.push({i,node});
                } else if(parent != i){
                    return true;
                }
            }
        }
        
        return false;
    }
    int isTree(int n, int m, vector<vector<int>> &B) {
        if (n-1 != m) {
            return 0;
        } 
        
        vector<int>visited(n,0);
        vector<int> adj[n];
        for(int i=0; i<B.size(); i++) {
            vector<int>temp = B[i];
            adj[temp[0]].push_back(temp[1]);
            adj[temp[1]].push_back(temp[0]);
        }
        
        for(int i=0; i < n; i++) {
            if(visited[i] == 0) {
                if(isCycle(i,visited,adj)) {
                    return 0;
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            if(visited[i] == 0) {
                return 0;
            }
        }
        
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends