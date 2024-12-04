//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool KMPSearch(string pat, string txt) {
        int M = pat.size();
        int N = txt.size();
        int lps[M];
        computeLPSArray(pat, M, lps);
        int i = 0;
        int j = 0; 
        while ((N - i) >= (M - j)) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }
            if (j == M) {
                return true;
            }
            else if (i < N && pat[j] != txt[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return false;
    }
    void computeLPSArray(string pat, int M, int *lps) {
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < M) {
            if (pat[i] == pat[len]) {
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
    }
    bool areRotations(string &s1, string &s2) {
        if (s1.length() != s2.length())
            return false;
        else {
            string concated = s1 + s1;
            if (KMPSearch(s2, concated))
                return true;
            else
                return false;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends