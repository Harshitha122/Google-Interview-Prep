class Solution {
public:
    void findcombination(int indx,vector<vector<int>> &ans,vector<int> &arr,vector<int> &ds,int target){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=indx;i<arr.size();i++){
            if(i>indx && arr[i]==arr[i-1])
                continue;
            if(arr[i]>target)
                break;
            ds.push_back(arr[i]);
            findcombination(i+1,ans,arr,ds,target-arr[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        findcombination(0,ans,candidates,ds,target);
        return ans;
    }
};