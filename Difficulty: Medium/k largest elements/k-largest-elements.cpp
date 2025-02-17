//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        int n = arr.size();
        // Min heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            if (pq.size() == k) {        // If the size of heap is equal to k
                if (pq.top() < arr[i]) { // If the top element of heap is smaller than
                                         // current element
                    pq.pop();            // Remove the smallest element from heap
                    pq.push(arr[i]);     // Insert the current element in heap
                }
            } else {
                pq.push(arr[i]); // If heap size is less than k, just insert the current
                                 // element in heap
            }
        }
        vector<int> ans;
        while (!pq.empty()) { // Pop elements from heap and store them in ans vector
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(
            ans.begin(),
            ans.end()); // Reverse the ans vector to get elements in descending order
        return ans;     // Return the k largest elements in an array
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
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.kLargest(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends