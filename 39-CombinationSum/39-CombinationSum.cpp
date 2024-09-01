class Solution {
public:
    void backtrack(vector<int> &candidates,int target,vector<vector<int>> &res,vector<int> &ans,int sum,int indx){
        if(sum>target)
            return;
        if(sum==target){
            res.push_back(ans);
        }
        for(int i=indx;i<candidates.size();i++){
            sum+=candidates[i];
            ans.push_back(candidates[i]);
            backtrack(candidates,target,res,ans,sum,i);
            sum-=candidates[i];
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        backtrack(candidates,target,res,ans,0,0);
        return res;
    }
};