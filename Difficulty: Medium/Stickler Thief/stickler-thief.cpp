//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();

        if (n == 0)
            return 0;
        if (n == 1)
            return arr[0];

        // Set previous 2 values
        int secondLast = 0, last = arr[0];

        // Compute current value using previous two values
        // The final current value would be our result
        int res;
        for (int i = 1; i < n; i++) {
            res = max(arr[i] + secondLast, last);
            secondLast = last;
            last = res;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends