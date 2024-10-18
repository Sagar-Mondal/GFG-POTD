//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        // variable to store the XOR of all elements in the array.
        int xr = 0;
        int n = arr.size();

        // iterating over all the elements in the array.
        for (int i = 0; i < n; i++) {
            // calculating XOR of each element with the previous XOR.
            xr = xr ^ arr[i];
        }

        // returning the element which occurs only once.
        return xr;
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
        int res = obj.getSingle(arr);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends