//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
     void solve(int ind, string &s, string &ds, vector<string> &ans){
                if(ind >= s.size()){
                    if(ds.size() > 0)
                    ans.push_back(ds);
                    return;
                }
                
                ds.push_back(s[ind]);
                solve(ind + 1, s, ds, ans);
                ds.pop_back();
                solve(ind + 1, s, ds, ans);
            }
        
    public:
    vector<string> AllPossibleStrings(string s){
        // Code here
        vector<string> ans;
        string ds;
        solve(0, s, ds, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends