//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int minValue = INT_MAX;
        int minIndex = -1;
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[low] <= arr[high]){
                if(arr[low] < minValue){
                    minValue = arr[low];
                    minIndex = low;
                }
                break;
            }
            if(arr[low] <= arr[mid]){
                if(arr[low] < minValue){
                    minValue = arr[low];
                    minIndex = low;
                }
                low = mid + 1;
            }
            else{
                if(arr[mid] < minValue){
                    minValue = arr[mid];
                    minIndex = mid;
                }
                high = mid - 1;
            }
        }
        return minIndex;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends