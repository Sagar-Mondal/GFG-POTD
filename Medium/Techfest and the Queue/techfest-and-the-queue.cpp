//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int sumOfPowers(int a, int b) {

        int mod = 1e9 + 7;

        std::vector<int> primes(b + 1, 0);


        for (int i = 2; i <= b; i++) {

            if (primes[i] == 0) {

                for (int j = i; j <= b; j += i) {

                    int count = 0;

                    int temp = j;

                    while (temp % i == 0) {

                        temp /= i;

                        count++;

                    }

                    primes[j] += count;

                }

            }
        }

        int result = 0;

        for (int i = a; i <= b; i++) {

            result = (result + primes[i]) % mod;

        }

 

 

        return result;

    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends