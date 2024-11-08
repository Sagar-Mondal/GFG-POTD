//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
      void computeLPSArray(string& str, vector<int>& lps)
    {
        int len = 0, idx = 1;
        lps[0] = 0;
        while (idx < str.length()) {
            if (str[idx] == str[len]) {
                len += 1;
                lps[idx] = len;
                idx += 1;
            }
            else {
                if (len == 0) {
                    lps[idx] = 0;
                    idx += 1;
                }
                else {
                    len = lps[len - 1];
                }
            }
        }
    }
    bool KMPSearch(string& txt, string& pat, vector<int>& lps)
    {
        int txtLen = txt.length(), patLen = pat.length();
        int i = 0;
        int j = 0; 
        while ((txtLen - i) >= (patLen - j)) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }
            if (j == patLen) {
                return true;
            }
            else if (i < txtLen && pat[j] != txt[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return false;
    }
    int minRepeats(string& A, string& B) {
            int lenA = A.length();
    int lenB = B.length();
    vector<int> lps(lenB);
    computeLPSArray(B, lps);
    int X = (lenB + lenA - 1) / lenA;
    string newA;
    for (int i = 0; i < X; i++) {
        newA.append(A);
    }
    if (KMPSearch(newA, B, lps))
        return X;
    newA.append(A);
    if (KMPSearch(newA, B, lps))
        return X + 1;
    return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends