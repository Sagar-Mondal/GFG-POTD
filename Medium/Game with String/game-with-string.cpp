//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
     int minValue(string s, int k){
        int freq[26]={0};
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            int idx = ch-'a';
            freq[idx]++;
        }
        while(k--){
            int maxidx=0;
            for(int i=0;i<26;i++){
                if(freq[i]>freq[maxidx]){
                    maxidx=i;
                }
            }
            freq[maxidx]--;
        }
        long long sum=0;
        for(int i=0;i<26;i++){
            sum+=pow(freq[i],2);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends