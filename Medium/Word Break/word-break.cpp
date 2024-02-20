//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings
struct Node{
    Node* child[26];
    bool isend;
    Node(){
        for(int i=0;i<26;i++)child[i]=NULL;
        isend=false;
    }
};

void insert(Node* root,string &s){
    for(auto &it:s){
        if(root->child[it-'a']==NULL)root->child[it-'a']=new Node();
        root=root->child[it-'a'];
    }
    root->isend=true;
}
class Solution
{
public:
vector<int>dp;
    int solve(int i,int n,string &s,Node* root){
        if(i==n)return 1;
        if(dp[i]!=-1)return dp[i];
        int ok=0;
        Node* temp=root;
        for(int j=i;j<n;j++){
            if(root->child[s[j]-'a']){
                root=root->child[s[j]-'a'];
                if(root->isend)ok|=solve(j+1,n,s,temp);
                if(ok)return 1;
            }
            else break;
        }
        return dp[i]=0;
    }
    int wordBreak(int n, string s, vector<string> &dict) {
        Node* root=new Node();
     for(auto &it:dict)insert(root,it);
     int m=s.size();
     dp=vector<int>(m+1,-1);
     return solve(0,m,s,root);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends