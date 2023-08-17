//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
       vector<int> ans;
        int arr[n];
        
        bool flag = false;
        for(int i=0; i<n/2; i++){
            arr[i] = num[i];
        }
        for(int i=0; i<n/2; i++){
            if(arr[n/2-1-i]>num[n - n/2+i]){
                flag = true;
                break;
            }
            else if(arr[n/2-1-i]<num[n-n/2+i]) break;
        }
        if(flag){
            vector<int> res;
            for(int i=0; i<n/2; i++){
                res.push_back(arr[i]);
            }
            if(n%2==1){
                res.push_back(num[n/2]);
            }
            for(int i=n/2-1; i>=0; i--){
                res.push_back(arr[i]);
            }
            
            return res;
        }
        
        int half[n-n/2];
        for(int i=0; i<n-n/2; i++){
            half[i] = num[i];
        }
        int carry = 1;
        for(int i=n-n/2-1; i>=0; i--){
            int x = half[i]+carry;
            carry = x/10;
            half[i] = x%10;
        }
        
        if(carry==1){
            ans.push_back(1);
            for(int i=0; i<n-1; i++){
                ans.push_back(0);
            }
            ans.push_back(1);
        }
        else{
            for(int i=0; i<n-n/2; i++){
                ans.push_back(half[i]);
            }
            for(int i=n/2-1; i>=0; i--){
                ans.push_back(half[i]);
            }
        }
        
        return ans;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends