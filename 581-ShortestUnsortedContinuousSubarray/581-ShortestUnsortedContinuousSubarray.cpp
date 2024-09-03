class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxi=nums[0];
        int n=nums.size();
        int mini=nums[n-1];
        int end=-1,start=0;
        for(int i=1;i<n;i++){
            if(maxi>nums[i]){
                end=i;
            }
            else{
                maxi=nums[i];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(mini<nums[i]){
                start=i;
            }
            else{
                mini=nums[i];
            }
        }
        return end-start+1;
    }
};