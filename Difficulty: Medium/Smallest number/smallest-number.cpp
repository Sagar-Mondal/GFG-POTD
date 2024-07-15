//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        if (d * 9 < s)
            return "-1";
        int n = pow(10, d - 1);
        int sum = s - 1;
        string temp = to_string(n);
        int i = d - 1;
        while (i >= 0 && sum > 0) {
            if (sum > 9) {
                temp[i] = '9';
                sum = sum - 9;
            } else {
                int val = temp[i] - '0';
                val = val + sum;
                temp[i] = '0' + val;
                sum = 0;
            }
            i--;
        }
        return temp;
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
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends