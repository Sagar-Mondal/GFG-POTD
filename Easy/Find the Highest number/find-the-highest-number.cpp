//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        if(arr.size()==1){
            return arr[0];
        }
        if(arr.size()==2){
            return max(arr[0],arr[1]);
        }
        int l = 1;
        int r = arr.size()-2;
        while(l<=r){
            int mid = (l+r)/2;
            if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]) return arr[mid];
            else if(arr[mid]>arr[mid-1] and arr[mid+1]>arr[mid]) l = mid+1;
            else r = mid-1;
        }
        if(arr[0]>arr[1]) return arr[0];
        return arr[arr.size()-1];
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends