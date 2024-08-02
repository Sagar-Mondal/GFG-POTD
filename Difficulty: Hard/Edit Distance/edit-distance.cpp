//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int ans(string &str1,string&str2,int n,int m,vector<vector<int>>&v)
    {
        if(n==-1)
        return m+1;
        if(m==-1)
        return n+1;
        if(v[n][m]!=INT_MAX)
        return v[n][m];
        if(str1[n]==str2[m])
        {
            return v[n][m]=min(v[n][m],ans(str1,str2,n-1,m-1,v));
        }
        v[n][m]=min(v[n][m],1+ans(str1,str2,n-1,m-1,v));
        v[n][m]=min(v[n][m],1+ans(str1,str2,n-1,m,v));
        v[n][m]=min(v[n][m],1+ans(str1,str2,n,m-1,v));
        return v[n][m];
        
    }
    int editDistance(string str1, string str2) {
        // Code here
        int n=str1.length(),m=str2.length();
        vector<vector<int>>v(n,vector<int>(m,INT_MAX));
        return ans(str1,str2,n-1,m-1,v);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends