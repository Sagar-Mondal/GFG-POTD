//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string& s) {
        vector<int> freq(26,0);
        int x = 0, y=0;
        for(char c : s)
            freq[c-'a']++;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                if(i%2==0 and freq[i]%2!=0)
                     y++;
                if(i%2!=0 and freq[i]%2==0)
                     x++;
            }
        }
        if((x+y)&1)
            return("ODD");
        return("EVEN");
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends