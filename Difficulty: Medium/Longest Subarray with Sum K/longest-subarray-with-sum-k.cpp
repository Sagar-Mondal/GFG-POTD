//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int>
            prefixSumIndices;
        int currentSum = 0, longestLength = 0;
        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i];
            if (currentSum == k)
                longestLength = i + 1;
            if (prefixSumIndices.find(currentSum - k) != prefixSumIndices.end()) {
                longestLength =
                    max(longestLength, i - prefixSumIndices[currentSum - k]);
            }
            if (prefixSumIndices.find(currentSum) == prefixSumIndices.end())
                prefixSumIndices[currentSum] = i;
        }
        return longestLength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends