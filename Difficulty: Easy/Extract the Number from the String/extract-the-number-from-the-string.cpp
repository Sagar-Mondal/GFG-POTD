//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string S) {
        long long int num = 0;
        long long int num2 = -1;
        int flag=0;
        for(int i=0;i<=S.size();i++)
        {
            if(S[i]>='0' && S[i]<='9')
            {
                num = num*10 + (S[i]-'0');
            }
            else if(num>0)
            {
                if(num>num2 )
                {
                    long long int temp = num;
                    while(num)
                    {
                        int r = num%10;
                        num = num/10;
                        if(r==9){
                        flag = 1;
                        break;
                        }
                    }
                    if(flag)
                    {
                     flag=0;
                     num = 0;
                    }
                   else{
                        num2=temp;
                   }
                }
                num=0;
            }
        }
        return num2;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends