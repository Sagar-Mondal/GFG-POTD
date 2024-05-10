//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    set<vector<int>> ans;
    void solve(int i,int k,vector<int>& arr,vector<int>& temp){
        if(k==0){
            ans.insert(temp);
            return ;
        }
        if(i>=arr.size()){
            return ;
        }
        
        // include
        if(k-arr[i]>=0){
            temp.push_back(arr[i]);
            solve(i+1,k-arr[i],arr,temp);
            temp.pop_back();
        }
        
        //exclude
        solve(i+1,k,arr,temp);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(),arr.end());
        vector<int> temp;
        solve(0,k,arr,temp);
        vector<vector<int>> vs(ans.begin(),ans.end());
        return vs;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends