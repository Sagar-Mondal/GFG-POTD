//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        int res = 0;

        // XOR all numbers from 1 to n-1 and
        // elements in the array
        for (int i = 0; i < n - 1; i++) {
            res = res ^ (i + 1) ^ arr[i];
        }

        // XOR the last element in the array
        res = res ^ arr[n - 1];

        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.findDuplicate(arr);

        cout << (result) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends