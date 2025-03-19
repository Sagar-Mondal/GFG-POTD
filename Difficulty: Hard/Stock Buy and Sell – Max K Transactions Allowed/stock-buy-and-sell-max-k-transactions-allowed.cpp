//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0 || k == 0)
            return 0;
        vector<vector<int>> curr(k + 1, vector<int>(2, 0));
        vector<vector<int>> next(k + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int l = 1; l <= k; l++) {
                curr[l][1] = max(-prices[i] + next[l][0], next[l][1]);
                curr[l][0] = max(prices[i] + next[l - 1][1], next[l][0]);
            }
            next = curr;
        }
        return curr[k][1];
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends