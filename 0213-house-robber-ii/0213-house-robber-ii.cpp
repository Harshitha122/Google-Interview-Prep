class Solution {
public:
    int robb(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1)return nums[0];
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        vector<int> nums1;
        vector<int> nums2;
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                nums1.push_back(nums[i]);
            }
            if(i!=n-1)
                nums2.push_back(nums[i]);
        }
        return max(robb(nums1),robb(nums2));
    }
};