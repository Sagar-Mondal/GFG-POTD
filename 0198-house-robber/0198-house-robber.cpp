class Solution {
public:
    int profit(vector<int> &nums, vector<int> &dp, int i){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=max(profit(nums,dp,i+1), nums[i]+profit(nums,dp,i+2));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return profit(nums,dp,0);
    }
};