//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution {
  public:
  ll help(ll n)
  {
      ll ans=0;
      for(int i=0;i<32;i++)
      {
          if(n &(1<< (31-i)))
          ans+= pow(2,i);
      }
      return ans;
  }
    long long reversedBits(long long x) {
        // code here
        return help(x);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends