//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int ans = 0;
        int n = prices.size();
        int st = prices[0], end = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                end = prices[i];
            } else {
                ans += end - st;
                st = prices[i];
                end = st;
            }
        }
        ans += end - st;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends