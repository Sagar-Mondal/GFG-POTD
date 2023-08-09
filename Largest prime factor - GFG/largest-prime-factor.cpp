//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        int largest_prime=0,i=2;
        while(i*i<=N){
            while(N%i==0){
                largest_prime=i;
                N/=i;
            }
            i++;
        }
        if(N>1){
            largest_prime=N;
        }
        return largest_prime;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends