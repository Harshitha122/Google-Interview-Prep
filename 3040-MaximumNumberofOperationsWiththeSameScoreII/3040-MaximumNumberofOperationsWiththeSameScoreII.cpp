class Solution {
public:
    vector<vector<int>>dp;
    int solve(int l,int r,int score,vector<int>&nums)
    {
        if(l>=r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        
        int ans=0;
        if(nums[l]+nums[l+1]==score)ans=max(ans,1+solve(l+2,r,score,nums));
        if(nums[r]+nums[r-1]==score)ans=max(ans,1+solve(l,r-2,score,nums));
        if(nums[l]+nums[r]==score)ans=max(ans,1+solve(l+1,r-1,score,nums));
        
        return dp[l][r]=ans;
    }
    int maxOperations(vector<int>& nums) {
        dp.resize(nums.size()+1,vector<int>(nums.size()+1,-1));
        int n=nums.size();
        int ans=0;
        ans=max(ans,1+solve(2,n-1,nums[0]+nums[1],nums));
        ans=max(ans,1+solve(0,n-3,nums[n-1]+nums[n-2],nums));
        ans=max(ans,1+solve(1,n-2,nums[0]+nums[n-1],nums));
        return ans;
    }
};