//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newEvent) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> res;
        while (i < n && intervals[i][1] < newEvent[0])
            res.push_back(intervals[i++]);
        while (i < n && newEvent[1] >= intervals[i][0]) {
            newEvent[0] = min(newEvent[0], intervals[i][0]);
            newEvent[1] = max(newEvent[1], intervals[i][1]);
            i++;
        }
        res.push_back(newEvent);
        while (i < n)
            res.push_back(intervals[i++]);
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
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends