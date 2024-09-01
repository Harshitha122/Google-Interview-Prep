class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n=nums.size();
        int i=0;
        int res=n;
        for(int num:nums){
        // Xor ing numbers and arr[num] simultaneously
            res^=num; 
            res^=i;
            i++;
        }
        return res;
    }
};