//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        int h[26] = {0};

        // using hash table to store count of each character.
        for (int i = 0; i < s.length(); i++) {
            h[s[i] - 'a']++;
        }
        bool flag = false;

        // iterating over the string.
        for (int i = 0; i < s.length(); i++) {
            // if count of current character is 1, we return it.
            if (h[s[i] - 'a'] == 1) {
                flag = true;
                return s[i];
            }
        }
        // if there is no non-repeating character then we return '$'.
        if (!flag) {
            return '$';
        }
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends