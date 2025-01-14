//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        long long sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum = sum - arr[i];
            if (sum2 == sum) {
                return i;
            }
            sum2 = sum2 + arr[i];
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends