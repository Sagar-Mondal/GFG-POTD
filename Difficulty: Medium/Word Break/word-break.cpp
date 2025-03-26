//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        int n = s.size();
        vector<bool> dp(n + 1, 0);
        dp[0] = 1;

        // Traverse through the given string
        for (int i = 1; i <= n; i++) {

            // Traverse through the dictionary words
            for (string &w : dictionary) {

                // Check if current word is present
                // the prefix before the word is also
                // breakable
                int start = i - w.size();
                if (start >= 0 && dp[start] && s.substr(start, w.size()) == w) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends