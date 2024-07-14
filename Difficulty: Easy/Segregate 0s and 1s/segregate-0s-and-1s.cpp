//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int cnt0 = 0, cnt1 = 0;
        for(int it : arr){
            if(it == 0) cnt0++;
            else    cnt1++;
        }
        int i = 0;
        while(cnt0 > 0){
            arr[i] = 0;
            cnt0--;
            i++;
        }
        while(cnt1 > 0){
            arr[i] = 1;
            cnt1--;
            i++;
        }
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
        int n = arr.size();
        Solution ob;
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends