//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
vector<int>arr;
int n;
vector<int>dp;

int rec(int i){
    if(i==0)return 1;
   if(dp[i]!=-1)return dp[i];
   dp[i]=1;
   for(int j=0;j<i;j++){
       if(arr[i]-arr[j]>=i-j)dp[i]=max(dp[i],1+rec(j));
   }
   return dp[i];
}
    int min_operations(vector<int>& nums) {
        // Code here
        arr=nums;
        n=arr.size();
        dp.assign(n+1,-1);
        int maxi=-1e9;
        for(int i=0;i<n;i++)maxi=max(maxi,rec(i));
       // cout<<maxi<<endl;
        return n-maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends