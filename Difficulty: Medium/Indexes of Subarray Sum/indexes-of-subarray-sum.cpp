//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int s = 0, e = 0;
        vector<int> res;
        int curr = 0;
        for (int i = 0; i < arr.size(); i++) {
            curr += arr[i];
            if (curr >= target) {
                e = i;
                while (curr > target && s < e) {
                    curr -= arr[s];
                    ++s;
                }
                if (curr == target) {
                    res.push_back(s + 1);
                    res.push_back(e + 1);
                    return res;
                }
            }
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends