//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& arr, int n) {
        vector<int> dp(n, -1);
        dp[0] = 0;
        for(int ind = 1; ind < n; ind++){
            int jump2 = INT_MAX;
            int jump1 = dp[ind - 1] + abs(arr[ind] - arr[ind - 1]);
            if(ind > 1){
                jump2 = dp[ind - 2] + abs(arr[ind] - arr[ind - 2]);
            }
            dp[ind] = min(jump1, jump2);
        }
        return dp[n - 1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends