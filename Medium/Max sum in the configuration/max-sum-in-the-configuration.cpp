//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        long long sum = 0;
        long long tsum = 0;
        long long val ;
        for(int i = 0 ;  i<n ;i++){
            val = i;
            sum+=a[i];
            tsum+=val*a[i];
        }
        long long maxi = tsum;
        long long N = n;

        for(int i = 1 ; i<n ;i++){
            tsum = tsum + sum - N*a[n-i];
            maxi = max(maxi,tsum);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends