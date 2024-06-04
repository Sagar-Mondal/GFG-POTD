//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        int n = s.length();
        int countOne = 0;
        int idxZero = -1;
        for(int i=0;i<n;++i){
            if(s[i] == '1') {
                ++countOne;
            } else {
                idxZero = i;
            }
        }
        string ans = "";
        if(countOne == n) {
            ans += "1";
            for(int i=0;i<n;++i) {
                ans += "0";
            }
        } else {
            s[idxZero] = '1';
            for(int i=idxZero+1;i<n;++i) {
                s[i] = '0';
            }
            int i = 0;
            while(s[i] == '0') ++i;
            for(int j=i;j<n;++j) {
                ans += s[j];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends