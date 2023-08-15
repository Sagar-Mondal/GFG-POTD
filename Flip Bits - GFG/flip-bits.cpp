//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Kadane’s Algorithm
        int curr_sum=0,max_sum=0,one_count=0;
        for(int i=0;i<n;i++){
            //before flipping
            if(a[i]==1){
                one_count++;
            }
            //after flipping
            int val=(a[i]==0)?1:-1;
            curr_sum+=val;
            max_sum=max(max_sum,curr_sum);
            if(curr_sum<0){
                curr_sum=0;
            }
        }
        int ans=one_count+max_sum;
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends