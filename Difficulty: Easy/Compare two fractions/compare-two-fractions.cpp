//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string s) {
        int n = s.length();
        int a=0,b=0,c=0,d=0;
        int i=0;
        while(i<n and s[i]!='/') {
            a = a*10+s[i]-'0';
            i++;
        }
        i++;
        while(i<n and s[i]!=',') {
            b = b*10+s[i]-'0';
            i++;
        }
        i++;
        i++;
        while(i<n and s[i]!='/') {
            c = c*10+s[i]-'0';
            i++;
        }
        i++;
        while(i<n) {
            d = d*10+s[i]-'0';
            i++;
        }
        if ((a/(1.0*b)) > (c/(1.0*d)))
            return to_string(a)+"/"+to_string(b);
        else if((a/(1.0*b)) < (c/(1.0*d)))
            return to_string(c)+"/"+to_string(d);
        return "equal";
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends