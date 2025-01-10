//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int, int> um;
        int n = arr.size();
        vector<int> result;
        for (int i = 0; i < k; i++)
            um[arr[i]]++;
        result.push_back(um.size());
        for (int i = 1; i < n - k + 1; i++) {
            um[arr[i - 1]]--;
            if (um[arr[i - 1]] <= 0)
                um.erase(arr[i - 1]);
            um[arr[i + k - 1]]++;
            result.push_back(um.size());
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends