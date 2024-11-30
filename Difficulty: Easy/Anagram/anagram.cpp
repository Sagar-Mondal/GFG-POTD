//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        int a[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            a[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.length(); i++) {
            a[s2[i] - 'a']--;
        }
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (a[i] != 0) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends