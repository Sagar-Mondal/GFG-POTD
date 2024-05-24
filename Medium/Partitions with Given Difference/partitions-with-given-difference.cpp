//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int MOD = 1e9 + 7;

    int countPartitions(int n, int d, vector<int>& arr) {
        int Sum = 0;
        for (int num : arr) {
            Sum += num;
        }
        
       
        if ((Sum + d) % 2 != 0 || Sum < d) {
            return 0;
        }
        
        int target = (Sum + d) / 2;
        
        
        vector<int> dp(target + 1, 0);
        dp[0] = 1; 
        
        
        for (int num : arr) {
            for (int j = target; j >= num; --j) {
                dp[j] = (dp[j] + dp[j - num]) % MOD;
            }
        }
        
        return dp[target];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends