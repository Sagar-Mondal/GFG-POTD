//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
 int solve(string &str,int idx,int prev,vector<vector<int>>&dp)
    {
        if(idx==str.size())
        {
            return 1;
        }
        if(dp[idx][prev]!=-1)
        {
            return dp[idx][prev];
        }
        int ans=0;
        int sum=0;
        for(int i=idx;i<str.size();i++)
        {
            sum+=(str[i]-'0');
            if(sum>=prev)
            {
                ans+=solve(str,i+1,sum,dp);
            }
        }
        return dp[idx][prev]=ans;
    }
    int TotalCount(string str){
        // Code here
        int n=str.size();
        vector<vector<int>>dp(n,vector<int>(1000,-1));
        return solve(str,0,0,dp);
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends