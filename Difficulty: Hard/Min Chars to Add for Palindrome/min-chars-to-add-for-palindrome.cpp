//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> computeLPSArray(string str) {
        int M = str.length();
        vector<int> lps(M);
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < M) {
            if (str[i] == str[len]) {
                len++;
                lps[i] = len;
                i++;
            } else
            {
                if (len != 0) {
                    len = lps[len - 1];
                } else 
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    int minChar(string& str) {
        string revStr = str;
        reverse(revStr.begin(), revStr.end());
        string concat = str + "$" + revStr;
        vector<int> lps = computeLPSArray(concat);
        return (str.length() - lps.back());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends