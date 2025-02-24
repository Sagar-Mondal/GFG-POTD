//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        s.push(0);
        vector<int> S(n);

        // span value of first day is always 1.
        S[0] = 1;

        for (int i = 1; i < n; i++) {
            // we pop elements from the stack till price at top of stack
            // is less than or equal to current price.
            while (s.empty() == false and arr[s.top()] <= arr[i])
                s.pop();

            // if stack becomes empty, then price[i] is greater than all
            // elements on left of it in list so span is i+1.
            // Else price[i] is greater than elements after value at top of stack.
            int span = (s.empty()) ? (i + 1) : (i - s.top());
            S[i] = span;

            // pushing this element to stack.
            s.push(i);
        }
        // returning the list.
        return S;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends