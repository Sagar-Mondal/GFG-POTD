//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> leftMaxHeap;
        priority_queue<int, vector<int>, greater<int>> rightMinHeap;
        vector<double> res;
        for (int i = 0; i < arr.size(); i++) {
            leftMaxHeap.push(arr[i]);
            int temp = leftMaxHeap.top();
            leftMaxHeap.pop();
            rightMinHeap.push(temp);
            if (rightMinHeap.size() > leftMaxHeap.size()) {
                temp = rightMinHeap.top();
                rightMinHeap.pop();
                leftMaxHeap.push(temp);
            }
            double median;
            if (leftMaxHeap.size() != rightMinHeap.size())
                median = leftMaxHeap.top();
            else
                median = (double)(leftMaxHeap.top() + rightMinHeap.top()) / 2;
            res.push_back(median);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends