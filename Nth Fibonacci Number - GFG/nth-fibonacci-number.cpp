//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        const unsigned int M = 1000000007;
        if(n<2)
            return n;
        int a=0,b=1,c=0;
        for(int i=1;i<n;i++){
            c=(a+b)%M;
            a=b;
            b=c;
        }
        return c%M;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends