//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    struct comp {
    bool operator()(const pair<double, int>& p1, const pair<double, int>& p2) {
       
        return p1.first < p2.first;
    }
};
    double fractionalKnapsack(int wt, Item arr[], int n)
    {
             priority_queue< pair<double,int> ,vector< pair<double,int>>,comp>pq;
             
            for(int i=0;i<n;i++){
                pq.push({arr[i].value/(double)arr[i].weight,arr[i].weight});
            }
          double ans=0;
          while(wt>0&&!pq.empty()){
              double a=pq.top().first;
              int b=pq.top().second;
                pq.pop();
             ans+=(min(b,wt)*a);
             wt-=min(b,wt);
           
          }
       return ans ;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends