class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            res+=maxi;
            maxi=max(maxi,nums[i]);
        }
        return res;
    }
};