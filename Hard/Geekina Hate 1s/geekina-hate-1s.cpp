//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long findNthNumber(long long n, int k) {
        long long low = 0, high = pow(10, 18);
        dp = std::vector<std::vector<std::vector<long long>>>(2, std::vector<std::vector<long long>>(65, std::vector<long long>(65, -1)));
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = find(mid, k);
            if (count >= n) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    long long find(long long n, int k) {
        std::string s = std::bitset<64>(n).to_string();
        reset();
        return dpf(s, s.length(), 1, k);
    }
    long long dpf(const std::string &s, int n, int tight, int k) {
        if (k < 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (dp[tight][k][n] != -1) {
            return dp[tight][k][n];
        }
        int ub = (tight == 1) ? s[s.length() - n] - '0' : 1;
        long long ans = 0;
        for (int dig = 0; dig <= ub; ++dig) {
            if (dig == ub) {
                ans += dpf(s, n - 1, tight, k - dig);
            } else {
                ans += dpf(s, n - 1, 0, k - dig);
            }
        }
        dp[tight][k][n] = ans;
        return ans;
    }

    void reset() {
        for (int i = 0; i < 65; ++i) {
            for (int j = 0; j < 65; ++j) {
                dp[0][i][j] = -1;
                dp[1][i][j] = -1;
            }
        }
    }

private:
    std::vector<std::vector<std::vector<long long>>> dp;
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        Solution obj;
        long long res = obj.findNthNumber(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends