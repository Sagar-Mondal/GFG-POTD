//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         int n=mat.size();
        vector<int> ans(n*n,0);
        int k=0;
        
        bool up=true;
        int r=0,c=0;
        while(r<n && c<n){
            if(up){
                while(r>0 && c<n-1){
                    ans[k++]=mat[r][c];
                    r--;
                    c++;
                    
                }
                ans[k++]=mat[r][c];
                if(c==n-1)
                    r++;
                else
                    c++;
            }
            else{
                while(c>0 && r<n-1){
                    ans[k++]=mat[r][c];
                    r++;
                    c--;
                    
                }
                ans[k++]=mat[r][c];
                if(r==n-1)
                    c++;
                else
                    r++;
            }
            up=!up;
        }
        
        return(ans);
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends