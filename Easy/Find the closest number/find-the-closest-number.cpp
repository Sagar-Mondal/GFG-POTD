//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int low=0;
        int high=n-1;
        
        while(low<=high){
            
            int mid= low+(high-low)/2;
            
            if(arr[mid]<=k and k<=arr[mid+1])
            return abs(arr[mid]-k)< abs(arr[mid+1]-k) ? arr[mid]: arr[mid+1];
            
            else if(k<arr[mid])
            high=mid-1;
            
            else
            low=mid+1;
        }
        return -1;
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
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends