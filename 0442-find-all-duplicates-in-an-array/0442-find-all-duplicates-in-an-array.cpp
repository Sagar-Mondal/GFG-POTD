class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return {};
        }
        vector<int> ans;
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second==2){
                ans.push_back(i->first);
            }
        }
        return ans;
    }
};