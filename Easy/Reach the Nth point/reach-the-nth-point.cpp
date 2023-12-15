//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
      int dp[100005];
            const int M = 1e9+7;
            int nthPoint(int n){
                if(dp[0]==0){
                    for(int i=0;i<100005;i++){
                        dp[i]=-1;
                    }
                }
                
               if(n==0 || n==1) return 1;
               if(dp[n]!=-1) return dp[n];
                   
               
               return dp[n]=(nthPoint(n-1)%M+nthPoint(n-2)%M)%M;
                
            }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends