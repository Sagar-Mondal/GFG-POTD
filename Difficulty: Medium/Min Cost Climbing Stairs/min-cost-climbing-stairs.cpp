//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int climb_one = 0;
        int climb_two = 0;
        int N = cost.size();
        // iterating through each step to find the minimum cost.
        for (int i = 2; i < N + 1; i++) {
            int res = climb_one;

            // calculating the minimum cost at the current step.
            climb_one = min(climb_one + cost[i - 1], climb_two + cost[i - 2]);

            // updating the value of climb_two for the next iteration.
            climb_two = res;
        }
        // returning the minimum cost to reach the top of the floor.
        return climb_one;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends