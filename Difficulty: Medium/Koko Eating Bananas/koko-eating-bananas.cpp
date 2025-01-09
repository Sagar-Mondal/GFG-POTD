//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long findTime(vector<int>& arr, int mid){
        long long res = 0;
        for(int i = 0; i < arr.size(); i++){
            res += ceil((double)arr[i] / (double)mid);
        }
        return res;
    }
    int kokoEat(vector<int>& arr, int k) {
        int maxi = *max_element(arr.begin(), arr.end());
        int low = 1, high = maxi;
        int ans = 1;
        while(low <= high){
            int mid = (low + high) / 2;
            long long totalTime = findTime(arr, mid);
            if(totalTime <= k){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
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

        cout << ob.kokoEat(arr, k);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends