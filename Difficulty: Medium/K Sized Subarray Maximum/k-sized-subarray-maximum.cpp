//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(const vector<int>& arr, int k) {

        // to store the results
        vector<int> res;

        // create deque to store max values
        deque<int> dq(k);

        // Process first k (or first window) elements of array
        for (int i = 0; i < k; ++i) {

            // For every element, the previous smaller elements
            // are useless so remove them from dq
            while (!dq.empty() && arr[i] >= arr[dq.back()]) {

                // Remove from rear
                dq.pop_back();
            }

            // Add new element at rear of queue
            dq.push_back(i);
        }
        // Process rest of the elements, i.e., from arr[k] to arr[n-1]
        for (int i = k; i < arr.size(); ++i) {

            // The element at the front of the queue is the largest
            // element of previous window, so store it
            res.push_back(arr[dq.front()]);

            // Remove the elements which are out of this window
            while (!dq.empty() && dq.front() <= i - k) {

                // Remove from front of queue
                dq.pop_front();
            }

            // Remove all elements smaller than the currently being
            // added element (remove useless elements)
            while (!dq.empty() && arr[i] >= arr[dq.back()]) {
                dq.pop_back();
            }

            // Add current element at the rear of dq
            dq.push_back(i);
        }

        // store the maximum element of last window
        res.push_back(arr[dq.front()]);

        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends