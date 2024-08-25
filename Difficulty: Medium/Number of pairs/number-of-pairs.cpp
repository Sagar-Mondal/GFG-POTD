//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int count(int x, vector<int> &y, int N, vector<int> &NoOfY) {
        if (x == 0)
            return 0;
        if (x == 1)
            return NoOfY[0];
        int idx = upper_bound(y.begin(), y.end(), x) - y.begin();
        int ans = N - idx;
        ans += (NoOfY[0] + NoOfY[1]);
        if (x == 2)
            ans -= (NoOfY[3] + NoOfY[4]);
        if (x == 3)
            ans += NoOfY[2];
        return ans;
    }
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        int M = arr.size(), N = brr.size();
        vector<int> NoOfY(5, 0);
        for (int i = 0; i < N; i++)
            if (brr[i] < 5)
                NoOfY[brr[i]]++;
        sort(brr.begin(), brr.end());
        long long total_pairs = 0;
        for (int i = 0; i < M; i++)
            total_pairs += count(arr[i], brr, N, NoOfY);
        return total_pairs;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends