//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > arr) {
        int n=arr.size();
        int m=arr[0].size();
        int ans=-1;
        int k=m;        
        for(int i=0;i<n;i++){
            int j;
            for(j=k-1;j>=0;j--){
                if(arr[i][j]==0){
                    if(k>(j+1)){
                        k=j+1;
                        ans=i;
                    }
                    break;    
                }    
            }
            if(j<0)
                return i;
        }        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends