//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int power(int mid, int n, int m){
        long long ans = 1;
        for(int i = 1; i <= n; i++){
            ans *= mid;
            if(ans > m){
                return -1;
            }
        }
        if(ans == m)    return 1;
        return 0;
    }
    int nthRoot(int n, int m) {
        int low = 1, high = m;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int midN = power(mid, n, m);
            if(midN == 1)   return mid;
            else if(midN == 0){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends