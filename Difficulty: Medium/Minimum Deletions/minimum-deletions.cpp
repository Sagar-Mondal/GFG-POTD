class Solution {
  public:
    int minDeletions(string &s) {
        int n = s.length();
        
        // We need 3 arrays: current and two previous rows
        vector<int> prev1(n, 0), curr(n, 0), prev2(n, 0);
        
        // Fill the dp table
        // l is the length of substring
        for (int l = 2; l <= n; l++) {
            
            // Update current row 
            for (int i = n-l; i >= 0; i--) {
                int j = i + l - 1;
                
                // If there are only 2 characters
                if (l == 2) {
                    curr[i] = (s[i] == s[j]) ? 0 : 1;
                } 
                else {
                    
                    // If first and last characters match
                    if (s[i] == s[j]) {
                        curr[i] = prev2[i+1];
                    } 
                    else {
                        // If they don't match, consider minimum of two choices
                        curr[i] = 1 + min(prev1[i], prev1[i+1]);
                    }
                }
            }
            // Update previous with current for next iteration
            prev2 = prev1;
            prev1 = curr;
        }
        
        // Return minimum deletions for entire string
        return prev1[0];
    }
};