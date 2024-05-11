//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> jugglerSequence(int n) {
        vector<int>ans;
        ans.push_back(n);
        while(n >= 1){
            if(ans[ans.size()-1]==1){
                break;
            }
            double t = pow(ans[ans.size()-1],0.5);
            double t1 = t*t*t;
            if(ans[ans.size()-1] % 2 == 0){
                ans.push_back(t);
            }   
            else{
                ans.push_back(t1);
            }
            if(ans[ans.size()-1]==1){
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends