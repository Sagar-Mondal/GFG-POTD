//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size(); 
        int m = mat[0].size(); 
        for (int i = 0; i < n; i++) {
            if (x >= mat[i][0] && x <= mat[i][m - 1]) {
                int left = 0, right = m - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (mat[i][mid] == x) {
                        return true; 
                    } else if (mat[i][mid] < x) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }
        return false; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends