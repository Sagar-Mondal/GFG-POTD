class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int lb=(lower_bound(nums.begin(),nums.end(),target)-nums.begin());
        if(lb==nums.size() || nums[lb]!=target){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        res.push_back(lb);
        res.push_back(upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1);
        return res;
    }
};