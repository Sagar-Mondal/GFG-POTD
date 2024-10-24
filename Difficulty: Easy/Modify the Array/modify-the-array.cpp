//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] != 0 && arr[i] == arr[i + 1]) {
                ans.push_back(2 * arr[i]);
                arr[i + 1] = 0;
            } else if (arr[i] == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(arr[i]);
            }
        }
        if (arr[n - 2] == arr[n - 1]) {
            ans.push_back(0);
        } else {
            ans.push_back(arr[n - 1]);
        }
        vector<int> mod;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (ans[i])
                mod.push_back(ans[i]);
            else
                c++;
        }
        for (int i = 0; i < c; i++)
            mod.push_back(0);
        return mod;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends