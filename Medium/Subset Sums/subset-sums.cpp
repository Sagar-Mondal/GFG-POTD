//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void subset(vector<int>& arr, vector<int>& res, int n, int ind, int sum){
        if(ind == n){
            res.push_back(sum);
            return;
        }
        subset(arr, res, n, ind + 1, sum + arr[ind]);
        subset(arr, res, n, ind + 1, sum);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> res;
        subset(arr, res, n, 0, 0);
        sort(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends