//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


#define aa long long
long long int countStr(long long int n){
    
    aa a=1; 
    aa b=n;  
    aa c=(n*(n-1))/2; 
    aa d=n; //np1 - 1 
    aa e=n*(n-1); 
    aa f=(n*(n-1)*(n-2))/2; 
    
    return (a+b+c+d+e+f);
}