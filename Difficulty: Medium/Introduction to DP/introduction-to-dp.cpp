//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const int mod = 1e9 + 7;
    long long int solveTopDown(int n, vector<long long int>& td){
        if(n <= 1){
            return td[n] = n;
        }
        if(td[n] != -1) return td[n];
        return td[n] = (solveTopDown(n - 1, td) + solveTopDown(n - 2, td)) % mod;
    }
    long long int topDown(int n) {
        vector<long long int> td(n + 1, -1);
        return solveTopDown(n, td);
    }
    long long int bottomUp(int n) {
        vector<long long int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends