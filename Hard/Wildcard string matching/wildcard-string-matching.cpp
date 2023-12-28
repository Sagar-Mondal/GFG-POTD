//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string pattern, string wild)
    {
    int n = wild.length();
    int m = pattern.length();
    int i = 0, j = 0, startIndex = -1, match = 0;
 
    while (i < n)
    {
        if (j < m && (pattern[j] == '?' || pattern[j] == wild[i]))
        {
            // Characters match or '?' in pattern matches any character.
            i++;
            j++;
        }
        else if (j < m && pattern[j] == '*')
        {
            // Wildcard character '*', mark the current position in the pattern and the text as a proper match.
            startIndex = j;
            match = i;
            j++;
        }
        else if (startIndex != -1)
        {
            // No match, but a previous wildcard was found. Backtrack to the last '*' character position and try for a different match.
            j = startIndex + 1;
            match++;
            i = match;
        }
        else
        {
            // If none of the above cases comply, the pattern does not match.
            return false;
        }
    }
 
    // Consume any remaining '*' characters in the given pattern.
    while (j < m && pattern[j] == '*')
    {
        j++;
    }
 
    // If we have reached the end of both the pattern and the text, the pattern matches the text.
    return j == m;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends