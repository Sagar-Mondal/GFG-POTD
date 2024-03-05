//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    int maxIndexDiff(int arr[], int n) {
        vector<int> prefix(n), suffix(n);
        prefix[0] = arr[0];
        suffix[n - 1] = arr[n - 1];
        
        for(int i = 1; i < n; i++){
            prefix[i] = min(prefix[i - 1], arr[i]);
            suffix[n - i - 1] = max(suffix[n - i], arr[n - i - 1]);
        }
        
        int i, j, ans;
        i = j = ans = 0;
        
        while(j < n){
            if(prefix[i] <= suffix[j]){
                ans = max(ans, j - i);
                ++j;
            }
            else{
                ++i;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends