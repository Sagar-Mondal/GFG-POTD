//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        map<pair<int,int>,int> freq;
        int count=0,x,y,z;
        for(int i=0;i<n;i++){
            int factor=__gcd(numerator[i],denominator[i]);
            numerator[i]=numerator[i]/factor;
            denominator[i]=denominator[i]/factor;
            x=numerator[i];
            y=denominator[i];
            z=y-x;
            if(freq.count({z,y})){
                count+=freq[{z,y}];
            }
            freq[{numerator[i],denominator[i]}]++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends