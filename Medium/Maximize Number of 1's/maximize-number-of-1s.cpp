//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        int l = 0, r = 0, zeros = 0, len = 0;
        while(r < n){
            if(arr[r] == 0) zeros++;
            if(zeros > m){
                if(arr[l] == 0) zeros--;
                l++;
            }
            if(zeros <= m)  len = max(len, r - l + 1);
            r++;
        }
        return len;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends