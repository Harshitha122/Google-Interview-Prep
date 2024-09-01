class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int sum=0;
        int len=INT_MAX;
        int i=0,j=0;
        int n=nums.size();
        while(i<n){
          sum+=nums[i++];
          while(sum>=target){
              len=min(len,i-j);
              sum-=nums[j++];
         }
       }
    return (len==INT_MAX)?0 :len;
    } 
   /* int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
        while (r < n) {
            sum += nums[r++];
            while (sum >= target) {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len; */
    
    /* int n = nums.size(), len = INT_MAX;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = n; i >= 0 && sums[i] >= s; i--) {
            int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;*/ 
    /*while (r < n) {
            sum += nums[r++];
            while (sum >= s) {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;*/
};