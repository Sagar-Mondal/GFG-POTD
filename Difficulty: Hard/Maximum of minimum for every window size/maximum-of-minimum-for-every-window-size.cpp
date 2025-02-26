//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 0);
        stack<int> s;

        // Array to store the length of the window
        // where each element is the minimum
        vector<int> len(n, 0);

        // Traverse through array to determine
        // window sizes using a stack
        for (int i = 0; i < n; i++) {

            // Process elements to find next smaller
            // element on the left
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                int top = s.top();
                s.pop();
                int windowSize = s.empty() ? i : i - s.top() - 1;
                len[top] = windowSize;
            }
            s.push(i);
        }

        // Process remaining elements in the stack
        // for right boundaries
        while (!s.empty()) {
            int top = s.top();
            s.pop();
            int windowSize = s.empty() ? n : n - s.top() - 1;
            len[top] = windowSize;
        }
        for (int i = 0; i < n; i++) {
            int windowSize = len[i] - 1; // 0-based indexing
            res[windowSize] = max(res[windowSize], arr[i]);
        }

        // Fill remaining entries in res[] to ensure
        // all are max of min
        for (int i = n - 2; i >= 0; i--)
            res[i] = max(res[i], res[i + 1]);

        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends