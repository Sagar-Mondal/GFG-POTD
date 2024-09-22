//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        vector<int> A(str.size(), 0);
        int j = 0, i = 1;
        while (i < str.size()) {
            if (str[i] == str[j]) {
                A[i] = j + 1;
                j++;
                i++;
            } 
            else {
                if (j == 0)
                    i++;
                else
                    j = A[j - 1];
            }
        }
        return A.back();
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends