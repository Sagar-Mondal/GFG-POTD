//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        vector<int> count(26,0);
        for(char c:str){
            count[c-'a']++;
        }
        int maxi=0, maxidx=0;
        for(int i=0;i<count.size();i++){
            if(count[i]>maxi){
                maxi=count[i];
                maxidx=i;
            }
        }
        if(maxi>(str.size()+1)/2){
            return "-1";
        }
        string ans=str;
        int idx=0;
        while(count[maxidx]>0){
            ans[idx]=char(maxidx+'a');
            idx+=2;
            count[maxidx]--;
        }
        for(int i=0;i<count.size();i++){
            while(count[i]>0){
                if(idx>=str.size()){
                    idx=1;
                }
                ans[idx]=char(i+'a');
                idx+=2;
                count[i]--;
            }
        }
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends