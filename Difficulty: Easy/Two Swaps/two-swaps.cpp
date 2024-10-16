//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void doOneSwap(int &n, vector<int> &arr) {
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                for (int j = i + 1; j < n; j++) {
                    if (arr[j] == i + 1) {
                        swap(arr[i], arr[j]);
                        return;
                    }
                }
            }
        }
    }
    bool checkSorted(vector<int> &arr) {
        int n = arr.size();
        int misMatch = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1)
                misMatch++;
        }
        if (n == 1)
            return false;
        if (misMatch == 0 || misMatch == 3)
            return true;
        if (misMatch != 4)
            return false;
        doOneSwap(n, arr);
        doOneSwap(n, arr);
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1)
                return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends