//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
    int cnt=0;
    int n=arr.size();
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < target) {
                j++;
            }
            else if (sum > target) {
                k--;
            }
            else {
               int ele1 = arr[j], ele2 = arr[k];
                int cnt1 = 0, cnt2 = 0;
                while (j <= k && arr[j] == ele1) {
                    j++;
                    cnt1++;
                }
                while (j<= k && arr[k] == ele2) {
                    k--;
                    cnt2++;
                }
                if (ele1 == ele2)
                    cnt += (cnt1 * (cnt1 - 1)) / 2;
                else
                    cnt += (cnt1 * cnt2);
            }
        }
    }
    return cnt;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends