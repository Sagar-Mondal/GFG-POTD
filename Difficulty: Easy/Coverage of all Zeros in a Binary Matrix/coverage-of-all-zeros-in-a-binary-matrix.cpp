//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        int cnt = 0;
        int m = mat.size(), n = mat[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0) {
                    if(j < n-1 and mat[i][j+1]) 
                        ++cnt;
                    if(j > 0 and mat[i][j-1]) 
                        ++cnt;
                    if(i < m-1 and mat[i+1][j]) 
                        ++cnt;
                    if(i > 0 and mat[i-1][j]) 
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends