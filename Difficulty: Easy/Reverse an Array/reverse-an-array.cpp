//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void reverseArrayRec(vector<int> &arr, int l, int r) {
        if(l >= r)
            return;
        swap(arr[l], arr[r]);
        reverseArrayRec(arr, l + 1, r - 1);
    }
    void reverseArray(vector<int> &arr) {
     int n = arr.size();
    reverseArrayRec(arr, 0, n - 1);
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

        Solution ob;
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends