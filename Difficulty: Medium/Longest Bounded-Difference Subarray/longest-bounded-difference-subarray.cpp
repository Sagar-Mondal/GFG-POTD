//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>&  nums, int limit) {
        deque<int>dec,inc;
        int n = nums.size();

        int left = 0,right = 0;
        // int ans = 0;
        vector<int>ans;
        int mx = 0;
        int ind = -1;
        while(right<n){
            while(!inc.empty() && inc.back()>nums[right]) inc.pop_back();
            inc.push_back(nums[right]);
            while(!dec.empty() && dec.back()<nums[right]) dec.pop_back();
            dec.push_back(nums[right]);

            //agar is window ke max and min ka diff greater than limit hai 
            //to window ko shrink karo jab tk ki ye condition fail na ho jaye
            while(!inc.empty() && !dec.empty() && dec.front()-inc.front()>limit){
                if(nums[left] == dec.front()) dec.pop_front();
                if(nums[left] == inc.front()) inc.pop_front();
                left++;
            } 
            if(right-left+1>mx){
                mx = right -left +1;
                ind = left;
            }
            right++;
        }
        while(ind<n && ans.size()!=mx){
            ans.push_back(nums[ind]);
            ind++;
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends