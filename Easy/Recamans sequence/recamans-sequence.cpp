//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int> sqn;
        set<int> st;
        sqn.push_back(0);
        st.insert(0);
        
        for(int i=1; i<=n; i++){
            int val= sqn[i-1]-i;
            if(val < 0){
                 val=sqn[i-1]+i;
                sqn.push_back(val);
                st.insert(val);
            }else{
                if(st.find(val)!= st.end()){
                    val=sqn[i-1]+i;
                }
                sqn.push_back(val);
                st.insert(val);
            }
        }
        return sqn;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends