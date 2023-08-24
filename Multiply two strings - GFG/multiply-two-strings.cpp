//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        int a = s1[0] == '-' ? -1 : 0;
        int b = s2[0] == '-' ? -1 : 0;

        int arr[n1 + n2] = {0}; // Use an array to store the intermediate products and result

        for (int i = n1 - 1; i >= 0; i--) {
            int k = i + n2;
            if (s1[i] != '-') {
                int carry = 0;
                for (int j = n2 - 1; j >= 0; j--) {
                    if (s2[j] != '-') {
                        int x = (s1[i] - '0') * (s2[j] - '0') + carry + arr[k];
                        arr[k] = x % 10;
                        carry = x / 10;
                        k--;
                    }
                }
                if (carry > 0) {
                    arr[k] = carry;
                }
            }
        }

        bool flag = true;
        string str;
        for (int i = 0; i < n1 + n2; i++) {
            while (i < n1 + n2 && flag == true && arr[i] == 0) {
                i++;
            }
            flag = false;
            if (i < n1 + n2) {
                str += to_string(arr[i]);
            }
        }

        if ((a < 0 && b >= 0) || (a >= 0 && b < 0)) {
            str = "-" + str;
        }

        if (str.length() == 0) {
            return "0";
        }

        return str; 
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends