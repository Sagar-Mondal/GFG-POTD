//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mod=1e9+7;
    int numberOfConsecutiveOnes(int n) {
        vector<int>dp(1e5+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        vector<int>fib(1e5+1);
        fib[1]=1;
        fib[2]=1;
        for(int i=3;i<=n;i++){
            fib[i]=(fib[i-1]%mod+fib[i-2]%mod)%mod;
        }
        for(int i=3;i<=n;i++){
            dp[i]=(2*dp[i-1]%mod + fib[i-1]%mod)%mod;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends