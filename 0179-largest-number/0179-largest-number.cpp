class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(auto it:nums){
            ans.push_back(to_string(it));
        }
        sort(ans.begin(),ans.end(),[](string &s1, string &s2){return s1+s2>s2+s1;});
        string res;
        for(auto s:ans){
            res+=s;
        }
        while(res[0]=='0' && res.length()>1){
            res.erase(0,1);
        }
        return res;
    }
};