//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    void check(vector<string>ans,map<string,int>&m)
    {
        int count=0;
        for(int i=0;i<ans.size();i++)
        {
            int count1=0,count0=0;
            bool t=true;
            for(int j=0;j<ans[i].size();j++)
            {
                
                if(ans[i][j]=='1')count1++;
                else count0++;
                
                if(count0>count1)
                {
                    t=false;
                    break;
                }
            }
            if(t)m[ans[i]]++;
        }

    }
 vector<string> NBitBinary(int n)
   {
     string s="";
     for(int i=0;i<n;i++)s+='1';
       map<string,int>m;
       m[s]++;
     //s[n-1]='0';
     int count=0;
     string f=s;
   
     for(int i=0;i<=n/2;i++)
     {
         f[n-i-1]='0';
         s=f;
         vector<string>ans;
         sort(s.begin(),s.end());
         do
         {
             ans.push_back(s);
         }while(next_permutation(s.begin(),s.end()));
         check(ans,m);
         
     }
     vector<string>ans;
     for(auto i:m)ans.push_back(i.first);
     reverse(ans.begin(),ans.end());
     return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends