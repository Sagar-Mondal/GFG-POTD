//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        int maxProfit(vector<int> &price){
            int n=price.size();
            vector<int> dp(n,0);   
            int ma=price[n-1];
            for(int i=n-2;i>=0;i--){
                dp[i]=max(dp[i+1],ma-price[i]);
                ma=max(ma,price[i]);
                
            } 
            int mi=price[0];
            for(int i=1;i<n;i++){
                dp[i]=max(dp[i-1],dp[i]+price[i]-mi);
                mi=min(mi,price[i]);
                
            } 
             
             return(dp[n-1]);  
               
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends