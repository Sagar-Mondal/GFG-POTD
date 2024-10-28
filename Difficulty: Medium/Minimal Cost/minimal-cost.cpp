//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for(int ind = 1; ind < n; ind++){
            int mini = INT_MAX;
            for(int j = 1; j <= k; j++){
                if(ind - j >= 0){
                    int energy = dp[ind - j] + abs(arr[ind] - arr[ind - j]);
                    mini = min(mini, energy);
                }
            }
            dp[ind] = mini;
        }
        return dp[n - 1];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends