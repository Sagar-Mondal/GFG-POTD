//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int findfirst(int arr[],int n,int k){
	    int low=0,high=n-1,firstidx=-1;
	    while(low<=high){
	        int mid=(low+high)/2;
	        if(arr[mid]==k){
	            firstidx=mid;
	            high=mid-1;
	        }
	        else if(arr[mid]<k){
	            low=mid+1;
	        }
	        else{
	            high=mid-1;
	        }
	    }
	    return firstidx;
	}
	int findlast(int arr[],int n,int k){
	    int low=0,high=n-1,lastidx=-1;
	    while(low<=high){
	        int mid=(low+high)/2;
	        if(arr[mid]==k){
	            lastidx=mid;
	            low=mid+1;
	        }
	        else if(arr[mid]<k){
	            low=mid+1;
	        }
	        else{
	            high=mid-1;
	        }
	    }
	    return lastidx;
	}
	int count(int arr[], int n, int x) {
	    int first=findfirst(arr,n,x);
	    if(first==-1){
	        return 0;
	    }
	    int last=findlast(arr,n,x);
	    int res=last-first+1;
	    return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends