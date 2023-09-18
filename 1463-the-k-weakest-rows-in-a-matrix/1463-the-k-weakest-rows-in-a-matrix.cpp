class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row=mat.size();
        for(int i=0;i<row;i++){
            mat[i].push_back(i);
        }
        int col=mat[0].size();
        sort(mat.begin(),mat.end());
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            ans[i]=mat[i][col-1];
        }
        return ans;
    }
};