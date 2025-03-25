//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    bool evaluate(int b1, int b2, char op) {
        if (op == '&')
            return b1 & b2;
        if (op == '|')
            return b1 | b2;
        return b1 ^ b2;
    }
    int countWays(string &s) {
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
        for (int i = 0; i < n; i += 2) {
            dp[i][i][1] = (s[i] == 'T');
            dp[i][i][0] = (s[i] == 'F');
        }
        for (int len = 2; len < n;
             len += 2) {
            for (int i = 0; i < n - len; i += 2) {
                int j = i + len;
                dp[i][j][0] = dp[i][j][1] = 0;
                for (int k = i + 1; k < j; k += 2) { 
                    char op = s[k];
                    int leftTrue = dp[i][k - 1][1], leftFalse = dp[i][k - 1][0];
                    int rightTrue = dp[k + 1][j][1], rightFalse = dp[k + 1][j][0];
                    if (evaluate(1, 1, op))
                        dp[i][j][1] += leftTrue * rightTrue;
                    if (evaluate(1, 0, op))
                        dp[i][j][1] += leftTrue * rightFalse;
                    if (evaluate(0, 1, op))
                        dp[i][j][1] += leftFalse * rightTrue;
                    if (evaluate(0, 0, op))
                        dp[i][j][1] += leftFalse * rightFalse;
                    if (!evaluate(1, 1, op))
                        dp[i][j][0] += leftTrue * rightTrue;
                    if (!evaluate(1, 0, op))
                        dp[i][j][0] += leftTrue * rightFalse;
                    if (!evaluate(0, 1, op))
                        dp[i][j][0] += leftFalse * rightTrue;
                    if (!evaluate(0, 0, op))
                        dp[i][j][0] += leftFalse * rightFalse;
                }
            }
        }
        return dp[0][n - 1][1]; 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends