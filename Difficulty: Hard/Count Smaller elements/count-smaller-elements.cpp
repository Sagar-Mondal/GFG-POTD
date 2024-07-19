//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    void merge(vector<pair<int,int>>& res, vector<int>& count, int l, int mid, int r){
        vector<pair<int,int>> temp;
        int i = l, j = mid + 1, k = 0;
        temp.resize(r - l + 1);
        while(i <= mid && j <= r){
            if(res[i].first <= res[j].first){
                temp[k++] = res[j++];
            }
            else{
                count[res[i].second] += r - j  + 1;
                temp[k++] = res[i++];
            }
        }
        while(i <= mid){
            temp[k++] = res[i++];
        }
        while(j <= r){
            temp[k++] = res[j++];
        }
        for(int i = l; i <= r; i++){
            res[i] = temp[i - l];
        }
    }
    void mergeSort(vector<pair<int,int>>& res, vector<int>& count, int l, int r){
        if(l == r){
            return;
        }
        int mid = (l + r) / 2;
        mergeSort(res, count, l, mid);
        mergeSort(res, count, mid + 1, r);
        merge(res, count, l, mid, r);
    }
    vector<int> constructLowerArray(vector<int> &arr) {
        int n = arr.size();
        vector<pair<int,int>> res(n);
        for(int i = 0; i < n; i++){
            res[i] = {arr[i], i};
        }
        vector<int>count(n, 0);
        mergeSort(res, count, 0, n - 1);
        return count;
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
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends