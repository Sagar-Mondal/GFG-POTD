//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void recurPermute(string &s, int low, vector<string> &res){
        if(low==s.size()-1){
            res.push_back(s);
            return;
        }
        for(int i=low;i<s.size();i++){
            swap(s[low],s[i]);
            recurPermute(s,low+1,res);
            swap(s[low],s[i]);
        }
    }
    vector<string> permutation(string &S)
    {
        vector<string> ans;
        recurPermute(S,0,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends