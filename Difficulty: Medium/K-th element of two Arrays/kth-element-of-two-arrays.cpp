//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kth(vector<int>& arr1, vector<int>& arr2, int s1, int e1, int s2, int e2,int k) {
        if (s1 == e1)
            return arr2[s2 + k];
        if (s2 == e2)
            return arr1[s1 + k];
        int m1 = (e1 - s1) / 2;
        int m2 = (e2 - s2) / 2;
        if (m1 + m2 < k) {
            if (arr1[s1 + m1] > arr2[s2 + m2])
                return kth(arr1, arr2, s1, e1, s2 + m2 + 1, e2, k - m2 - 1);
            else
                return kth(arr1, arr2, s1 + m1 + 1, e1, s2, e2, k - m1 - 1);
        }
        else{
            if (arr1[s1 + m1] > arr2[s2 + m2])
                return kth(arr1, arr2, s1, s1 + m1, s2, e2, k);
            else
                return kth(arr1, arr2, s1, e1, s2, s2 + m2, k);
        }
    }
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int nn = arr1.size();
        int mm = arr2.size();
        return kth(arr1, arr2, 0, nn, 0, mm, k - 1);
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends