//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int subArraySum(vector<int>& arr, int tar) {
        unordered_map<int, int> map;
        int n = arr.size();
        int curr_sum = 0;
        int count = 0;
        unordered_map<int, int>::iterator x;
        for (int i = 0; i < n; i++) {
            curr_sum = curr_sum + arr[i];
            if (curr_sum == tar) {
                count++;
            }
            x = map.find(curr_sum - tar);
            if (x != map.end())
                count += x->second;
            map[curr_sum]++;
        }
        return count;
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
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends