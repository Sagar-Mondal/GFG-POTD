//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        if(str.size() < 26)  return false;
        unordered_set<char> st;
        for(int i = 0; i < str.size(); i++){
            if(str[i] != ' '){
                st.insert(str[i]);
            }
        }
        return st.size() + k >= 26;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends