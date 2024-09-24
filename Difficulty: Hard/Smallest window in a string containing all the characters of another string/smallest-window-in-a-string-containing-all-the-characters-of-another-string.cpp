//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    string smallestWindow (string s, string p) {
        if(p.length()>s.length()) {
            return "-1";
        }
        else {
            int shash[26]={0};
            int phash[26]={0};
            for(int i=0;i<p.length();i++) {
                phash[p[i]-'a']++;
            }
            int counter=0;
            int begin=0;
            int startindex=-1;
            int length=0;
            int minlength=INT_MAX;
            for(int i=0;i<s.length();i++) {
                shash[s[i]-'a']++;
                if(phash[s[i]]-'a'!=0&&shash[s[i]-'a']<=phash[s[i]-'a']) {
                    counter++;
                }
                if(counter==p.length()) {
                    while(shash[s[begin]-'a']>phash[s[begin]-'a']||phash[s[begin]-'a']==0) {
                        if(shash[s[begin]-'a']>phash[s[begin]-'a'])
                        shash[s[begin]-'a']--;
                        begin++;
                    }
                    length=i-begin+1;
                    if(length<minlength) {
                        startindex=begin;
                        minlength=length;
                    }
                    
                }
            }
            if(startindex==-1)
                return "-1";
            else
                return s.substr(startindex,minlength);
        }
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
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends