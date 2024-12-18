//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(vector<int> &arr, int n, int k, int curMin) {
        int studentsRequired = 1;
        int curSum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > curMin)
                return false;
            if (curSum + arr[i] > curMin) {
                studentsRequired++;
                curSum = arr[i];
                if (studentsRequired > k)
                    return false;
            }
            else {
                curSum += arr[i];
            }
        }
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        int sum = 0;
        if (n < k)
            return -1;
        for (int i = 0; i < n; ++i)
            sum += arr[i];
        int start = 0;
        int end = sum, mid;
        int ans = INT_MAX;
        while (start <= end) {
            mid = (start + end) / 2;
            if (isPossible(arr, n, k, mid)) {
                ans = min(ans, mid);
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends