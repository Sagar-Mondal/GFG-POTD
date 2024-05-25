//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int N, int k) {
        int r = N - 1; 
        long long sum = 0;
        for(int i = 0; i < k; i++){
            sum += cardPoints[i];
        }
        long long maxSum = sum;
        for(int i = k - 1; i >= 0; i--){
            sum -= cardPoints[i];
            sum += cardPoints[r];
            maxSum = max(maxSum, sum);
            r--;
        }
        return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends