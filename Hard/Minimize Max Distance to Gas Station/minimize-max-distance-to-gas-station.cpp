//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int n;
    int fn(double x, vector <int>& v) {
        int ret = 0;
        for (int i = 0; i < v.size() - 1; i++)
            ret += ceil((v[i + 1] - v[i]) / x) - 1;
        return ret;
    }
  public:
    double findSmallestMaxDist(vector<int> &s, int k) {
        // Code here
        double l=0;
        n = s.size();
        sort(s.begin(), s.begin()+n);
        double h = s[n-1] - s[0];
        while (h-l >= 1e-6) {
            double mid = (l+h) / 2.0;
            int x = fn(mid, s);
            if (x>k)
                l = mid;
            else
                h = mid;
        }
        return h;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends