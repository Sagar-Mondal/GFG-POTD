//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(int arr[],int n,int k,int t){
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=arr[i];
            if(k == 0) return false;
            if(sum == t){
                sum = 0;
                k--;
            }
            else if(sum >t){
                sum = arr[i];
                if(arr[i]>t) return false;
                k--;
            }
        }
        if(sum!=0 and k == 0) return false;
        return true;
    }
    int splitArray(int arr[] ,int N, int K) {
        int l = 1;
        int r = accumulate(arr,arr+N,0ll);
        int ans;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(arr,N,K,mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends