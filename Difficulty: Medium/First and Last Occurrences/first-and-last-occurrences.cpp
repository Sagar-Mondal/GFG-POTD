//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        int n = arr.size();
        vector<int> ans;
        int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int last = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
        if(first == n || arr[first] != x){
            first = -1;
            last = -1;
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
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
        int x;
        cin >> x;
        cin.ignore();
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, x);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends