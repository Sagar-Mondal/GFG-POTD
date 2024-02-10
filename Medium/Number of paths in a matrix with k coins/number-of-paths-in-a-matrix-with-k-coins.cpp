//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long dp[101][101][101];
    
    long long solve(int x, int y,int n, int k, vector<vector<int>>& arr){
        if(x >= n or y >= n or k<0) return 0ll;
        if(x == n-1 and y == n-1 and k - arr[x][y] == 0) return 1ll;
        if(dp[k][x][y]!=-1) return dp[k][x][y];
        return  dp[k][x][y] = solve(x+1,y,n,k-arr[x][y],arr) + solve(x,y+1,n,k-arr[x][y],arr); 
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        memset(dp,-1,sizeof(dp));
        return solve(0ll,0ll,n,k,arr);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends