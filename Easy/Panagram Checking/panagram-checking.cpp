//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
     bool checkPangram (string s) {
        // your code here
        vector<bool> alphabet(26,false);
    
        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] >= 'A' && s[i] <= 'Z') {
                
                char lowercase = (s[i]^(1 << 5));
                int index = lowercase - 'a';
                alphabet[index] = true;
            } else if(s[i] >= 'a' && s[i] <= 'z') {
                 
                int index = s[i]-'a';
                alphabet[index] = true;
        
            }
            
            
        }
        
        for(int i = 0; i < 26; i++) {
            if(!alphabet[i])
                return false;
        }   
        return true;
        
    }


};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends