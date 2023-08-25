//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    bool helper(string A, string B, string C,long long int i,long long int j,long long int k,vector<vector<int>> &dp){
        if(i<0 && j<0 && k<0){
            return true;
        }
        if(i>=0 && j>=0 && dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>=0 && A[i]==C[k] && j>=0 && B[j]==C[k]){
            return dp[i][j]=(helper(A,B,C,i-1,j,k-1,dp) || helper(A,B,C,i,j-1,k-1,dp));
        }
        else if(i>=0 && A[i]==C[k]){
            return helper(A,B,C,i-1,j,k-1,dp);
        }
        else if(j>=0 && B[j]==C[k]){
            return helper(A,B,C,i,j-1,k-1,dp);
        }
        else{
            return false;
        }
    }
    bool isInterleave(string A, string B, string C) 
    {
        if(A.size()+B.size()!=C.size()){
            return false;
        }
        vector<vector<int>> dp(A.size()+1,(vector<int>(B.size()+1,-1)));
        return helper(A,B,C,A.size()-1,B.size()-1,C.size()-1,dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends