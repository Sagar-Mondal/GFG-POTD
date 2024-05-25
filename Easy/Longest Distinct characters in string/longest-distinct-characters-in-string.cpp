//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    vector<int> mp(256, -1);
    int l = 0, r = 0, len = 0, maxLen = 0;
    while(r < S.size()){
        if(mp[S[r]] != -1){
            if(mp[S[r]] >= l){
                l = mp[S[r]] + 1;
            }
        }
        mp[S[r]] = r;
        len = r - l + 1;
        maxLen = max(maxLen, len);
        r++;
    }
    return maxLen;
}