//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    int mod = 1e9 + 7;
	    long int a = 1, b = 2, c = 2;
	    for(int i = 2; i <= N; i++){
	        c = (a + b) % mod;
	        a = b;
	        b = c;
	    }
	    c = (c * c) % mod;
	    return (int)c;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends