//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxValTab(int x, int y, vector<int>& arr) {
        int n = arr.size();
        int prev2 = arr[x];
        int prev1 = max(arr[x], arr[x + 1]);
        for (int j = x + 2; j <= y; j++) {
            int take = arr[j] + prev2;
            int noTake = prev1;
            int curr = max(take, noTake);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return arr[0];
        int ans = 0;
        ans = max(ans, maxValTab(0, n - 2, arr));
        ans = max(ans, maxValTab(1, n - 1, arr));

        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends