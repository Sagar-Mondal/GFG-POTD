//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
 bool check(vector<vector<int>> &mat2, int n, int x){
    int i = 0;
    int j = n-1;
    while(i >= 0 && i < n && j >= 0 && j < n){
        if(mat2[i][j] == x){
            return true;
        }
        else if(mat2[i][j] < x){
            i++;
        }
        else j--;
    }
    return false;
}
int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
{
    // Your code goes here
    int cnt = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            int c = x - mat1[i][j];
            if(check(mat2,n,c)){
                cnt++;
            }
        }
    }
    return cnt;
}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends