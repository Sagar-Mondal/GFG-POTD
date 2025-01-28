//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void genPermutations(int n, string &curr, unordered_map<char, int> &cnt,
                         vector<string> &res) {
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }
        for (pair<char, int> it : cnt) {
            char c = it.first;
            int count = it.second;
            if (count == 0)
                continue;
            curr.push_back(c);
            cnt[c]--;
            genPermutations(n, curr, cnt, res);
            curr.pop_back();
            cnt[c]++;
        }
    }
    vector<string> findPermutation(string s) {
        vector<string> res;
        unordered_map<char, int> cnt;
        for (char c : s)
            cnt[c]++;
        string curr = "";
        genPermutations(s.size(), curr, cnt, res);
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends