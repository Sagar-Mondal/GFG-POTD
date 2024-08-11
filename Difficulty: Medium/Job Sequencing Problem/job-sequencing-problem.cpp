//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    class DSU {
    public:
        vector<int> parent;
        DSU(int N) {
            parent.resize(N + 1);
            for (int i = 0; i <= N; i++) {
                parent[i] = i;
            }
        }
        int find(int x) {
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootY] = rootX;
            }
        }
    };
    vector<int> JobScheduling(Job arr[], int N) {
        sort(arr, arr + N, [](Job a, Job b) { return a.profit > b.profit; });
        int maxDeadline = 0;
        for (int i = 0; i < N; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        DSU dsu(100000); // Initialize DSU with a large value
        int profit = 0, jobsDone = 0;
        for (int i = 0; i < N; i++) {
            int availableSlot = dsu.find(arr[i].dead);
            if (availableSlot > 0) {
                dsu.unite(availableSlot - 1, availableSlot);
                profit += arr[i].profit;
                jobsDone++;
            }
        }
        return {jobsDone, profit};
    }
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends