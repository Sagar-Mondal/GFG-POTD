//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void DFS(vector<vector<char>>& M, int r, int c) {
        int ROW = M.size();
        int COL = M[0].size();
        if (r < 0 || c < 0 || r >= ROW || c >= COL || M[r][c] != '1') {
            return;
        }
        M[r][c] = '0';
        vector<int> rNbr = {1, -1, 0, 0, 1, -1, 1, -1};
        vector<int> cNbr = {0, 0, 1, -1, 1, -1, -1, 1};
        for (int i = 0; i < 8; ++i) {
            int newR = r + rNbr[i];
            int newC = c + cNbr[i];
            DFS(M, newR, newC);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        int count = 0;
        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (grid[r][c] == '1') {
                    count++;
                    DFS(grid, r, c);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends