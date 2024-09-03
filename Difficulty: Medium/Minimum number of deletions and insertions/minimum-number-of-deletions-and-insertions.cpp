//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
    int minOperations(string str1, string str2) 
    { 
        int m = str1.size();
        int n = str2.size();
        
        int L[m+1][n+1]; 
       int i, j; 
        
       // Following steps build L[m+1][n+1] in bottom 
       // up fashion. Note that L[i][j] contains  
       // length of LCS of str1[0..i-1] and str2[0..j-1]  
       for (i=0; i<=m; i++) 
       { 
         for (j=0; j<=n; j++) 
         { 
          if (i == 0 || j == 0) 
             L[i][j] = 0; 
        
           else if (str1.at(i-1) == str2.at(j-1)) 
             L[i][j] = L[i-1][j-1] + 1; 
        
           else
             L[i][j] = max(L[i-1][j], L[i][j-1]); 
         } 
       } 
          
       // L[m][n] contains length of LCS  
       // for X[0..n-1] and Y[0..m-1]  
       return m + n - 2*L[m][n];
    } 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends