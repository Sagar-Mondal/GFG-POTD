//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
         int d=0, i=0, j=0;
        while(i>=0 && i<n && j>=0 && j<m){
            d=(d+matrix[i][j])%4;
            if(matrix[i][j]==1)
            matrix[i][j]=0;
            
            if(d==0){
                j++;
                if(j==m)
                {
                    j--;
                    break;
                }
            }
            else if(d==1){
                i++;
                if(i==n)
                {
                    i--;
                    break;
                }
            }
            else if(d==2){
                j--;
                if(j==-1)
                {
                    j++;
                    break;
                }
            }
            else if(d==3){
                i--;
                if(i==-1)
                {
                    i++;
                    break;
                }
            }
        }
        
        return {i, j};
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
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends