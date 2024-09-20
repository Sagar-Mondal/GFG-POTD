//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int countBuildings(vector<int> &height){
        int n = height.size();
        stack<int> s;
        vector<int> ans;
        s.push(-1);
        for (int i = 0; i < n; i++){
            int k = height[i];
            while (s.top() < k && s.top() != -1){
                s.pop();
            }
            ans.push_back(s.top());
            s.push(k);
        }
        int count = 0;
        for (int i = 0; i < n; i++){
            if (ans[i] == -1){
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> height;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            height.push_back(number);
        }
        Solution ob;
        int ans = ob.countBuildings(height);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends