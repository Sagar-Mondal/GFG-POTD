//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to check if a string is Pangram or not.
    bool checkPangram(string& s) {
        vector<bool> arr(26, false);
        for(int i = 0 ; i < s.size(); i++){
            if('A' <= s[i] && s[i] <= 'Z'){
                arr[s[i] - 'A'] = true;
            }
            else if('a' <= s[i] && s[i] <= 'z'){
                arr[s[i] - 'a'] = true;
            }
        }
        for(int i = 0; i < 26; i++){
            if(arr[i] == false){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver Program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
    return (0);
}

// } Driver Code Ends