//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        set<vector<int>> resSet;
        int n = arr.size();
        unordered_map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                mp[arr[i] + arr[j]].push_back({i, j});
        }
        for (int i = 0; i < n; i++) {
            int rem = -arr[i];
            if (mp.find(rem) != mp.end()) {
                vector<pair<int, int>> pairs = mp[rem];
                for (auto p : pairs) {
                    if (p.first != i && p.second != i) {
                        vector<int> curr = {i, p.first, p.second};
                        sort(curr.begin(), curr.end());
                        resSet.insert(curr);
                    }
                }
            }
        }
        vector<vector<int>> res(resSet.begin(), resSet.end());
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

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends