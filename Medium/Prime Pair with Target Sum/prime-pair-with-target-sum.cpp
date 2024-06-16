//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    void Sieve(int n, bool isPrime[]){
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i <= n; i++){
            isPrime[i] = true;
        }
        for(int p = 2; p * p <= n; p++){
            if(isPrime[p] == true){
                for(int i = p * p; i <= n; i += p){
                    isPrime[i] = false;
                }
            }
        }
    }
    vector<int> getPrimes(int n) {
        bool flag = true;
        vector<int> res;
        bool isPrime[n + 1];
        Sieve(n, isPrime);
        for(int i = 0; i < n; i++){
            if(isPrime[i] && isPrime[n - i]){
                res.push_back(i);
                res.push_back(n - i);
                flag = false;
                break;
            }
        }
        if(flag)    return {-1, -1};
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends