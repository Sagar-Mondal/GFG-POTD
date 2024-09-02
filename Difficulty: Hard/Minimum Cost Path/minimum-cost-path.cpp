//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
struct cell
{
int x;
int y;
int distance;
bool operator<(cell other)const{
if(distance == other.distance){
if(x != other.x)
return x < other.x;
return y < other.y;
}
return distance < other.distance;
}
};
vector<int>dx = {-1,1,0,0};
vector<int>dy = {0,0,1,-1};
bool isValid(int x, int y, int n, int m){
return (x >=0 and x < n and y >=0 and y < m);
}
    int minimumCostPath(vector<vector<int>>& grid) 
    {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dp(n, vector<int>(m, INT_MAX));
    set<cell>st;
    st.insert({0,0,0});
    dp[0][0] = grid[0][0];
    while(!st.empty())
    {
    auto cur = *st.begin();
    st.erase(st.begin());
    for(int i = 0; i < 4; i++)
    {
    int x = cur.x + dx[i];
    int y = cur.y + dy[i];
    if(isValid(x,y,n,m) and dp[x][y]>dp[cur.x][cur.y]+grid[x][y])
    {
    if(dp[x][y] != INT_MAX)
    st.erase(st.find({x, y, dp[x][y]}));
    dp[x][y] = dp[cur.x][cur.y] + grid[x][y];
    st.insert({x, y, dp[x][y]});
    }
    }
    }
    return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends