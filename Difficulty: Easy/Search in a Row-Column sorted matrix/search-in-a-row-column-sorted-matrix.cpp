//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &arr, int x) {
        int n = arr.size(), m = arr[0].size();
        int r = 0, c = m - 1;

        // iterating until we reach the end of the rows or columns.
        while (r < n and c >= 0) {
            // if the current element is equal to the target element, return 1.
            if (arr[r][c] == x)
                return 1;

            // if the current element is greater than the target element,
            // decrease the column index.
            if (arr[r][c] > x)
                c--;

            // if the current element is less than the target element,
            // increase the row index.
            else
                r++;
        }
        // if the target element is not found in the matrix, return 0.
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends