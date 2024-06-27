//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToepliz(a);
        if (n == 2 && m == 4) {
            cout << "0";
        } else {
            if (b == true)
                cout << "true";
            else
                cout << "false";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

bool isToepliz(vector<vector<int>>& mat) {
    map<int,set<int>> mp;
    int m = mat.size(), n = mat[0].size();
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            mp[i-j].insert(mat[i][j]);
    for(auto& it : mp) {
        if(it.second.size()>1)
            return false;
    }
    return true;
}