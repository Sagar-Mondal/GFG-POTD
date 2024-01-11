//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        int n=s.size();
        vector<int>v(10,0);
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&s[i]<st.top()&&k>0)
            {
                st.pop();
                k--;
            }
            if(st.empty()&&s[i]=='0')
            continue;
            st.push(s[i]);
        }
        while(!st.empty()&&k--)
        {
           st.pop();
        }

       if(st.empty())
       {
       return "0";
       }
       string ans="";

        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends