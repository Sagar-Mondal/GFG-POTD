//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int lo = 0, hi = arr.size() - 1;
        int res = arr.size() + k;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] > mid + k) {
                res = mid + k;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends