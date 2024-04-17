//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int countPairs(int arr[] , int n ) 
    {
        int prod[n];
        int ans = 0;
        int len = 0;
        for(int i = 0; i < n; i++){
            int curr = arr[i]*i;
            int ind = upper_bound(prod, prod + len, curr) - prod;
            ans += len - ind;
            if(ind == len){
                prod[len] = curr;
            }else{
                for(int j = len; j > ind; j--){
                    prod[j] = prod[j - 1];
                }
                prod[ind] = curr;
            }
            len++;
        }
        // for(int i = 0; i < n; i++){
        //     cout << prod[i] << '\n';
        // }
        return ans;
        // 0 4 4 1
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends