//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> row{-1,-1,0,1,1,1,0,-1};
        vector<int> col{0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    int count=0;
                    for(int k=0;k<8;k++){
                        int nr=i+row[k];
                        int nc=j+col[k];
                        if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]==0){
                            count++;
                        }
                    }
                    if(count>0 && count%2==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends