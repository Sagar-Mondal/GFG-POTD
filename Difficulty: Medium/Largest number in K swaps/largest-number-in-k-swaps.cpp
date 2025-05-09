//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    void match(string &curr, string &result) {
      
        // If current number is larger, update result
        if (curr > result) {
            result = curr;
        }
    }
    
    // Function to set highest possible digits at given index
    void setDigit(string &s, int index, string &res, int k) {
      
        // Base case: If no swaps left or index reaches 
        // the last character, update result
        if (k == 0 || index == s.size() - 1) {
            match(s, res);
            return;
        }
    
        int maxDigit = 0;
    
        // Finding maximum digit for placing at given index
        for (int i = index; i < s.size(); i++) {
            maxDigit = max(maxDigit, s[i] - '0');
        }
    
        // If the digit at current index is already max
        if (s[index] - '0' == maxDigit) {
            setDigit(s, index + 1, res, k);
            return;
        }
    
        // Try swapping with the maximum digit found
        for (int i = index + 1; i < s.size(); i++) {
          
            // If max digit is found at current position
            if (s[i] - '0' == maxDigit) {
              
                // Swap to get the max digit at the required index
                swap(s[index], s[i]);
    
                // Call the recursive function to set the next digit
                setDigit(s, index + 1, res, k - 1);
    
                // Backtrack: swap the digits back
                swap(s[index], s[i]);
            }
        }
    }
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        string res = s;
        setDigit(s, 0, res, k);
    
        // Returning the result
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends