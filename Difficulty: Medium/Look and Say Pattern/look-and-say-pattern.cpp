//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        if(n == 1){
            return "1";
        }
        string say = lookandsay(n - 1);
        string res = "";
        for(int i = 0; i < say.length(); i++){
            char ch = say[i];
            int count = 1;
            while(i < say.length() - 1 && say[i] == say[i + 1]){
                count++;
                i++;
            }
            res += to_string(count) + string(1, ch);
        }
        return res;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends