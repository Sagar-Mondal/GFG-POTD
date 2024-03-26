//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool isAdditiveSequence(string n) {
        int size = n.size();
        for(int j=0;j<min(10,size-2);j++){
            long long prev1 = stoll(n.substr(0,j+1));
            for(int k=j+1;k<min(10,size-1);k++){
                long long prev2 = stoll(n.substr(j+1,k-j));
                int f = 0;
                for(int i=k+1;i<size;){
                    long long sum = prev1+prev2;
                    int sumSize = to_string(sum).size();
                    if(i+sumSize-1>=size){
                        f = 1;
                        break;
                    }
                    long long num = stoll(n.substr(i,sumSize));
                    if(num != sum){
                        f = 1;
                        break;
                    }
                    prev1 = prev2;
                    prev2 = num;
                    i+=sumSize;
                }
                if(!f)return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends