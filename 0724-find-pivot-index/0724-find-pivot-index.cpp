class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right=accumulate(nums.begin(),nums.end(),0);
        int left=0;
        for(int i=0;i<nums.size();i++){
            right-=nums[i];
            if(left==right){
                return i;
            }
            left+=nums[i];
        }
        return -1;
    }
};