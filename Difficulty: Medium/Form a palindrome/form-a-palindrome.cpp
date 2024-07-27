//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int lcs(string x, string y, int m, int n){
        int l[m + 1][n + 1];
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0){
                    l[i][j] = 0;
                }
                else if(x[i - 1] == y[j - 1]){
                    l[i][j] = l[i - 1][j - 1] + 1;
                }
                else{
                    l[i][j] = max(l[i - 1][j], l[i][j - 1]);
                }
            }
        }
        return l[m][n];
    }
    void reverseStr(string& s){
        int n = s.length();
        for(int i = 0; i < n / 2; i++){
            swap(s[i] , s[n - 1 - i]);
        }
    }
    int countMin(string str){
        int n = str.length();
        string rev = str;
        reverseStr(rev);
        return n - lcs(str, rev, n, n);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends