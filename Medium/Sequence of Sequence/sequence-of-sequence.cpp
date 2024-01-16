//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int numberSequence(int m, int n){
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 0; i < m  + 1; i++){
            for(int j = 0; j < n + 1; j++){
                if(i == 0 || j == 0 || i < j){
                    dp[i][j] = 0;
                }
                else if(j == 1){
                    dp[i][j] = i;
                }
                else{
                    dp[i][j] = dp[i / 2][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends