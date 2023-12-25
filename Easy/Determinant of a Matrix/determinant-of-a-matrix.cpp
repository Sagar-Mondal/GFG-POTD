//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        if(n == 1) return matrix[0][0];
        if(n == 2) return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
        int det = 0;
        for(int i = 0, sign = 1; i < n; i++, sign = -sign){
            vector<vector<int>> small_matrix(n-1, vector<int>(n-1));
            int a = 0;
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                for(int k = 1; k < n; k++) small_matrix[k-1][a] = matrix[k][j];
                a++;
            } 
            det += sign * matrix[0][i] * determinantOfMatrix(small_matrix, n-1);
        }
        return det;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends