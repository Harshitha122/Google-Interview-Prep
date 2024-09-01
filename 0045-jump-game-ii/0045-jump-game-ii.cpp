
       class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        int n=nums.size();
        int steps=nums[0];
        if(steps==0)
            return -1;
        int jump=1;
        int maxreach=nums[0];
        for(int i=1;i<n;i++){
            if(i==n-1){
                return jump;
            }
            maxreach=max(maxreach,i+nums[i]);
            steps--;
            if(steps==0){
                jump++;
                if(i>=maxreach){
                    return -1;
                }
                steps=maxreach-i;
            }
        }
        return -1;
    }
};
   