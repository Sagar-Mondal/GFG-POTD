//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int totalrowsum=0,rowsum=0,colsum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                totalrowsum+=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            int temprowsum=0,tempcolsum=0;
            for(int j=0;j<n;j++){
                temprowsum+=matrix[i][j];
                tempcolsum+=matrix[j][i];
            }
            rowsum=max(rowsum,temprowsum);
            colsum=max(colsum,tempcolsum);
        }
        int maxi=max(rowsum,colsum);
        return (maxi*n)-totalrowsum;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends