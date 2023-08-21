//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    vector<int> spirallyTraverse(vector<vector<int>> mat,int r,int c) {
     
      vector<int> ans;
      int top = 0, left = 0, bottom = r - 1, right = c - 1;
      while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
          ans.push_back(mat[top][i]);
    
        top++;
        for (int i = top; i <= bottom; i++)
          ans.push_back(mat[i][right]);
    
        right--;
        if (top <= bottom) {
          for (int i = right; i >= left; i--)
           ans.push_back(mat[bottom][i]);
    
          bottom--;
        }
        if (left <= right) {
          for (int i = bottom; i >= top; i--)
            ans.push_back(mat[i][left]);
    
          left++;
        }
      }
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends