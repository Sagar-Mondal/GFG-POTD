//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int f(int i, int j, string &pattern, string &str, vector<vector<int>> &dp) {
        if (i < 0 && j < 0) return 1;
        if (i < 0 && j >= 0) return 0;
        if (i >= 0 && j < 0) {
            for (int ii = i; ii >= 0; ii--) {
                if (pattern[ii] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (pattern[i] == str[j] or pattern[i] == '?') return dp[i][j] = f(i-1, j-1, pattern, str, dp);
        if (pattern[i] == '*') return dp[i][j] = f(i-1, j, pattern, str, dp) or f(i, j-1, pattern, str, dp);
        return dp[i][j] = false;
    }

    int wildCard(string pattern, string str) {
        int n = pattern.length();
        int m = str.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, pattern, str, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends