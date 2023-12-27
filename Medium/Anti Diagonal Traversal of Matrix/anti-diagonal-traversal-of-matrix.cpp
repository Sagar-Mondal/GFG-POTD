//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> v) 
    {
        int n = v.size();
        if (n == 0 ) {};
        vector<int> ans;
        
        vector<vector<bool>> visited(n, vector<bool> (n, 0));
        queue< pair < int, int >> q;
        q.push({0,0});
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                pair<int,int> qf = q.front();
                q.pop();
                int x = qf.first;
                int y = qf.second;
                ans.push_back(v[x][y]);
                
                if ( y + 1 < n && !visited[x][y+1]) {
                    q.push({x, y+1});
                    visited[x][y+1] = true;
                }
                if( x + 1 < n && !visited[x+1][y] ) {
                    q.push({x+1, y});
                    visited[x+1][y] = true;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends