class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return {};
        }
        int start = nums[0];
        int end = nums[0];
        vector<string> res;
        for (int i = 1; i < size; i++) {
            if (nums[i] == end) {
                continue;
            }
            if (nums[i] == end + 1) {
                end = nums[i];
                continue;
            }
            if (start == end) {
                res.push_back(to_string(end));
            } else {
                res.push_back(to_string(start) + "->" + to_string(end));
            }
            start = nums[i];
            end = nums[i];
        }
        if (start == end) {
            res.push_back(to_string(end));
        } else {
            res.push_back(to_string(start) + "->" + to_string(end));
        }
        return res;
        
        
      /*  vector<string> res;
       // if(n==0)
            //return res;
        int n=nums.size();
        if(n==0)
            return res;
        for(int i=0;i<n;i++){
            long long int start=nums[i];
            while(nums[i]+1==nums[i+1] && i!=n-1){
                //s+=nums[i];
                i++; 
            }
            long long int end=nums[i];
            if(start==end)
                res.push_back(to_string(start));
            else{
                res.push_back(to_string(start)+"->" + to_string(nums[i]));
            
        }
                             }
        return res;
        
         /*  vector<string> res;
        
        for (int i = 0, n = nums.size(); i < n; i++) {    
            int begin = nums[i];
            while (i != (n - 1) && nums[i] == nums[i + 1] - 1)
                i++;
            int end = nums[i];
            if (begin == end) 
                res.push_back(to_string(begin));
            else 
                res.push_back(to_string(begin)  + "->" + to_string(nums[i])); 
        }
        
        return res;*/ 
    }
};