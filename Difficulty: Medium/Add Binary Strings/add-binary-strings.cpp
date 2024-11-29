//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        int i = s1.length() - 1, j = s2.length() - 1;
        string res = "";
        char carry = '0';
        while (i >= 0 || j >= 0 || carry == '1') {
            char ch1 = (i >= 0) ? s1[i] : '0';
            char ch2 = (j >= 0) ? s2[j] : '0';
            int temp = (ch1 - '0') + (ch2 - '0') + (carry - '0');
            if (temp == 0) {
                res += '0';
                carry = '0';
            } else if (temp == 1) {
                res += '1';
                carry = '0';
            } else if (temp == 2) {
                res += '0';
                carry = '1';
            } else {
                res += '1';
                carry = '1';
            }
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        int pos = res.find_first_not_of('0');
        if (pos != string::npos) {
            return res.substr(pos);
        }
        return "0";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends