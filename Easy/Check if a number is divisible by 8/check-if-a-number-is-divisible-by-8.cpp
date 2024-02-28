//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        int n = s.size();
        if(n<=3){
            int a = stoi(s);
            if(a%8==0)return 1;
            else return -1;
        }
        string lastThreeDigit = s.substr(n-3,3);
        int a = stoi(lastThreeDigit);
        return a%8==0?1:-1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends