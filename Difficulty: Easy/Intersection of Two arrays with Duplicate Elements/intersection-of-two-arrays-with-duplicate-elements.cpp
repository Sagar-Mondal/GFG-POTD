//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        map<int , int> mp1 , mp2;
        for(int i = 0 ; i < n ; i++) {
            mp1[a[i]]++;
        }
        for(int i = 0 ; i < m ; i++) {
            mp2[b[i]]++;
        }
        map<int , int> :: iterator itr;
        vector<int> result;
        for(itr = mp2.begin() ; itr != mp2.end() ; itr++) {
            int ele = itr->first;
            if(mp1[ele]) {
                result.push_back(ele);
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        vector<int> res = ob.intersectionWithDuplicates(arr1, arr2);
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            cout << "[]" << endl;
        } else {
            for (auto it : res)
                cout << it << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends