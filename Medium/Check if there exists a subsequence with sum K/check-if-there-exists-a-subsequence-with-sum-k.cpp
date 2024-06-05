//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool check(int n, vector<int>& arr, int k, int i, int s){
        if(s > k){
            return false;
        }
        if(i == n){
            if(s == k){
                return true;
            }
            return false;
        }
        s += arr[i];
        if(check(n, arr, k, i + 1, s))  return true;
        s -= arr[i];
        if(check(n, arr, k, i + 1, s))  return true;
        return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return check(n, arr, k, 0, 0);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends