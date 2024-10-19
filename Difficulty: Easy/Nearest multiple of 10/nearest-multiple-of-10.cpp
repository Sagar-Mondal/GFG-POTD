//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        int n = str.size();

        // If the last digit is less then or equal to 5
        // then it can be rounded to the nearest
        // (previous) multiple of 10 by just replacing
        // the last digit with 0
        if (str[n - 1] - '0' <= 5) {

            // Set the last digit to 0
            str[n - 1] = '0';

            // Print the updated number
            return str.substr(0, n);
        }

        // The number hast to be rounded to
        // the next multiple of 10
        else {

            // To store the carry
            int carry = 0;

            // Replace the last digit with 0
            str[n - 1] = '0';

            // Starting from the second last digit, add 1
            // to digits while there is carry
            int i = n - 2;
            carry = 1;

            // While there are digits to consider
            // and there is carry to add
            while (i >= 0 && carry == 1) {

                // Get the current digit
                int currentDigit = str[i] - '0';

                // Add the carry
                currentDigit += carry;

                // If the digit exceeds 9 then
                // the carry will be generated
                if (currentDigit > 9) {
                    carry = 1;
                    currentDigit = 0;
                }

                // Else there will be no carry
                else
                    carry = 0;

                // Update the current digit
                str[i] = (char)(currentDigit + '0');

                // Get to the previous digit
                i--;
            }

            // If the carry is still 1 then it must be
            // inserted at the beginning of the string
            if (carry == 1)
                cout << carry;

            // Prin the rest of the number
            return str.substr(0, n);
        }
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends