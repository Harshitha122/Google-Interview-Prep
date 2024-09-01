class Solution {
public:
    void recur(vector<vector<int>> &ans,vector<int> &nums,int indx){
        if(indx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=indx;i<nums.size();i++){
            swap(nums[i],nums[indx]);
            recur(ans,nums,indx+1);
            swap(nums[indx],nums[i]);
        }
    }
        
        
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> ans;
         recur(ans,nums,0);
        return ans;
    }
};