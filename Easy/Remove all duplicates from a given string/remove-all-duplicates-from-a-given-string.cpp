//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
 string removeDuplicates(string str) {
     vector<int> v1(26,0),v2(26,0);
     string s="";
     for(char& ch:str){
         if(ch>='A'&&ch<='Z'){
             if(v1[ch-'A']==0){
                 s.push_back(ch);
             }
             v1[ch-'A']++;
         }
         if(ch>='a'&&ch<='z'){
             if(v2[ch-'a']==0){
                 s.push_back(ch);
             }
             v2[ch-'a']++;
         }
     }
     return s;
 }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends