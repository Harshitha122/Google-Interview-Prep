class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i1=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int i2=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(i1<nums.size() && nums[i1]==target)
            return {i1,i2-1};
        return {-1,-1};
    }
};