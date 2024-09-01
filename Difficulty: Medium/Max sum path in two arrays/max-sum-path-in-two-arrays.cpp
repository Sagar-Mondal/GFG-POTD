//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int i = 0, j = 0;
        int result = 0, sum1 = 0, sum2 = 0;
        int m = arr1.size(), n = arr2.size();
        // Using two pointers to iterate over two arrays
        while (i < m && j < n) {
            // if ar1 is smaller than ar2, incresing ar1 and adding its value to sum1
            if (arr1[i] < arr2[j])
                sum1 += arr1[i++];
            // if ar2 is smaller than ar1, incresing ar2 and adding its value to sum2
            else if (arr1[i] > arr2[j])
                sum2 += arr2[j++];
            // if ar1=ar2, checking the maximum sum obtained from both the arrays
            // updating result and sum1 and sum2 is again changed to zero
            else {
                result += max(sum1, sum2);
                sum1 = 0, sum2 = 0;
                while (i < m && j < n && arr1[i] == arr2[j]) {
                    result = result + arr1[i++];
                    j++;
                }
            }
        }
        // if jth pointer reaches end
        while (i < m)
            sum1 += arr1[i++];
        // if ith pointer reaches end
        while (j < n)
            sum2 += arr2[j++];

        // last maximum sum to be added after the end of the loop
        result += max(sum1, sum2);

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends