//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int atoi(string s) {
        bool neg=0;
        int n=s.length();
        int ans=0;
        for(int i=0; i<n; i++){
            if(i==0 && s[i]=='-'){
                neg=1;
                continue;
            }
            if(s[i]>='0' && s[i]<='9'){
                ans=(ans*10)+(s[i]-'0');
            }else return -1;
        }
        return neg?(-1)*ans:ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends