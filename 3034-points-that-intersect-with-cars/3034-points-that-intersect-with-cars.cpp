class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int row=nums.size();
        int col=nums[0].size();
        set<int> s;
        for(int i=0;i<row;i++){
            int start=nums[i][0];
            int end=nums[i][1];
            for(int j=start;j<=end;j++){
                s.insert(j);
            }
        }
        return s.size();
    }
};