//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
 int longSubarrWthSumDivByK(int arr[], int n, int k)
 {
     map<int,int> m;
        m[0]=-1;
        int sum=0;
        int rem;
        int largest=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            rem=sum%k;
            if(rem<0) rem+=k;
            auto itr=m.find(rem);
            if(itr!=m.end()) 
            {
                if((i-itr->second)>largest) largest=i-itr->second;
            }
            else m[rem]=i;
       }
       return largest;
 }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends