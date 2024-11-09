//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string findSum(string str1, string str2) {
        if (str1.length() > str2.length())
            swap(str1, str2);
        string str = "";
        int n1 = str1.length(), n2 = str2.length();
        int diff = n2 - n1;
        int carry = 0;
        for (int i = n1 - 1; i >= 0; i--) {
            int sum = ((str1[i] - '0') + (str2[i + diff] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        for (int i = n2 - n1 - 1; i >= 0; i--) {
            int sum = ((str2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry)
            str.push_back(carry + '0');
        reverse(str.begin(), str.end());
        return str;
    }
    string minSum(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        string a, b;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0 && i != n - 1)
                continue;
            if (i & 1)
                a += (char)(arr[i] + '0');
            else
                b += (char)(arr[i] + '0');
        }
        return findSum(a, b);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends