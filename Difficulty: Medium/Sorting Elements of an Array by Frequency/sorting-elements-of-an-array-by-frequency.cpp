//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    unordered_map<int, int> m;
    static bool sortByVal(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
    vector<int> sortByFreq(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            m[arr[i]]++;
        }
        copy(m.begin(), m.end(), back_inserter(v));
        sort(v.begin(), v.end(), sortByVal);
        vector<int> ans;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].second; j++) {
                ans.push_back(v[i].first);
            }
        }
        m.clear();
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
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends