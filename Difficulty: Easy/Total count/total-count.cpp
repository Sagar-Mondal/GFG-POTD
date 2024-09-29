//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        // iterating over all the elements.
        for (int i = 0; i < n; i++) {
            // if element is divisible by k, adding quotient to count.
            if (arr[i] % k == 0) {
                count += arr[i] / k;
            } else {
                // if not divisible, adding quotient + 1 to count.
                count += (arr[i] / k + 1);
            }
            // increasing count by 1 if element is 0.
            if (arr[i] == 0) {
                count++;
            }
        }
        // returning total count.
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.totalCount(k, arr);
        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends