class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int count0=0;
        int res=0;
        while(i<n){
            if(nums[i]==0){
                count0++;
            }
            while(count0>1){
                if(nums[j]==0){
                    count0--;
                }
                j++;
            }
            res=max(res,(i-j+1));
            i++;
        }
        return res;
    }
};