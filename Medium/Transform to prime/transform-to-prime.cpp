//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution
{
    public:
    bool isPrime(int n)
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            return 0;
        }
        return 1;
    }
    
    int minNumber(int arr[],int N)
    {
        ll sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        
        ll temp=sum;
        while(1)
        {
            if(isPrime(temp))
            return temp-sum;
            else
            temp++;
        }
        
        return 0;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends