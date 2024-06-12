//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool has4(int n){
        while(n != 0){
            if(n % 10 == 4) return true;
            n /= 10;
        }
        return false;
    }
    int countNumberswith4(int n) {
        int res = 0;
        for(int i = 1; i <= n; i++){
            res += has4(i) ? 1 : 0;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends