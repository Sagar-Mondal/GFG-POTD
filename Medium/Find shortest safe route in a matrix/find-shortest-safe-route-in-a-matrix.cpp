//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m , vector<int>(n , 0));
        
        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,1,0,-1};
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j] = 1;
                    for(int k=0;k<4;k++)
                    {
                        int newRow = delRow[k] + i;
                        int newCol = delCol[k] + j;
                        
                        if(newRow >=0 && newRow<m && newCol >=0 && newCol<n)
                        {
                            vis[newRow][newCol] = 1;
                        }
                    }
                }
            }
        }
        queue<pair<int , pair<int,int>>>q;
        for(int i=0;i<m;i++)
        {
            if(!vis[i][0] && mat[i][0]!=0)
            {
                q.push({0 , {i , 0}});
            }
        }
        
        vector<vector<int>>dis(m , vector<int>(n , INT_MAX));
        int ans = INT_MAX;
        while(!q.empty())
        {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            q.pop();
            
            if(col == n-1) ans = min(ans , dis+1);
            vis[row][col] = 1;
            
            for(int k=0 ;k<4;k++)
            {
                int newRow = delRow[k] + row;
                int newCol = delCol[k] +col;
                if(newRow >=0 && newRow<m && newCol >=0 && newCol<n  
                && !vis[newRow][newCol] && mat[newRow][newCol]==1)
                {
                    vis[newRow][newCol]=1;
                    q.push({dis+1 , {newRow , newCol}});
                }
            }
            
        }
        
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends