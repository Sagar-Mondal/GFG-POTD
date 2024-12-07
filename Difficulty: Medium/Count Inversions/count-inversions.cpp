//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int my_counter = 0;
    void merge(vector<int> &arr, int p, int q, int r) {
        int l = q - p + 1;
        int l2 = r - q;

        vector<int> arr1(l), arr2(l2);

        // Storing elements present in left half in arr1.
        for (int i = 0; i < l; i++) {
            arr1[i] = arr[i + p];
        }
        // Storing elements present in right half in arr2.
        for (int i = 0; i < l2; i++) {
            arr2[i] = arr[q + i + 1];
        }

        int left = 0, right = 0, k = p;

        // Merging two arrays while counting inversions.
        while (left < l && right < l2) {
            if (arr1[left] <= arr2[right]) {
                arr[k++] = arr1[left++];
            } else {
                arr[k++] = arr2[right++];
                // Counting inversions.
                my_counter += (l - left);
            }
        }
        while (left < l) {
            arr[k++] = arr1[left++];
        }

        // Adding remaining elements from arr2 if any.
        while (right < l2) {
            arr[k++] = arr2[right++];
        }
    }

    // Function to apply merge sort and count inversions.
    void mergeSort(vector<int> &arr, int p, int r) {
        if (p < r) {
            int q = (p + r) / 2;

            // Recursively sorting both halves.
            mergeSort(arr, p, q);
            mergeSort(arr, q + 1, r);

            // Merging the sorted halves and counting inversions.
            merge(arr, p, q, r);
        }
    }

    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        my_counter = 0; // Resetting counter for each test case.
        mergeSort(arr, 0, arr.size() - 1);
        return my_counter;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends