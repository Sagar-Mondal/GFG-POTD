//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
//#include<Windows.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long max_Books(int a[], int n, int k) {
        long long sum=0, temp=0;
       for(int i=0; i<n ; i++)
        {
            if(a[i]<=k)
             {
                 temp+=a[i];
             }
             else
              {
                  sum=max(sum, temp);
                  temp=0;
              }
        }
        sum = max(sum, temp);
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends