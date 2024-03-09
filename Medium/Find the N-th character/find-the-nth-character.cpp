//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        string temp = s;
        for (int i = 0;i < r; i++) {
            string ans =  "";
            for (auto j :temp) {
                if (j == '1') ans += "10";
                else ans += "01";
                if (ans.size()>n) break;
            }
            temp = ans;
        }
        
        return temp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends