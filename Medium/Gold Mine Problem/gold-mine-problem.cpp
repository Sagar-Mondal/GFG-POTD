//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i =0; i<n; i++){
            dp[i][m-1] = M[i][m-1];
            ans = max(ans,dp[i][m-1]);
        }
        for(int j=m-2; j>=0; j--){
            for(int i=0; i<n; i++){
                if(i-1>=0 && j+1<m){
                    dp[i][j] = max(dp[i][j],dp[i-1][j+1]);
                }
                if(j+1<m){
                    dp[i][j] = max(dp[i][j],dp[i][j+1]);
                }
                if(i+1<n && j+1<m){
                    dp[i][j] = max(dp[i][j],dp[i+1][j+1]);
                }
                dp[i][j]+=M[i][j];
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends