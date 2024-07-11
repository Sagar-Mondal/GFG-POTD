//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dfs(vector<vector<int>>& grid, int i, int j, int index) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1)
            return 0;
        grid[i][j] = index;
        int count = dfs(grid, i + 1, j, index) + dfs(grid, i - 1, j, index) +
                    dfs(grid, i, j + 1, index) + dfs(grid, i, j - 1, index);
        return count + 1;
    }
    void findNeighbours(vector<vector<int>>& grid, int i, int j, set<int>& s) {
        int n = grid.size();
        if (i > 0)
            s.insert(grid[i - 1][j]);
        if (j > 0)
            s.insert(grid[i][j - 1]);
        if (i < n - 1)
            s.insert(grid[i + 1][j]);
        if (j < n - 1)
            s.insert(grid[i][j + 1]);
    }
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0, index = 2, count;
        map<int, int> area;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    area[index] = dfs(grid, i, j, index);
                    res = max(res, area[index++]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> s;
                    findNeighbours(grid, i, j, s);
                    count = 1;
                    for (int i : s)
                        count += area[i];
                    res = max(res, count);
                }
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends