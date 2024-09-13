class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
    vector<int> sameParityPrefix(n, 0);
    
    // Preprocess the array to find the number of same parity pairs up to each index
    for (int i = 1; i < n; ++i) {
        sameParityPrefix[i] = sameParityPrefix[i - 1] + ((nums[i - 1] % 2) == (nums[i] % 2));
    }
    
    vector<bool> result;
    
    // Process each query
    for (const auto& query : queries) {
        int from = query[0];
        int to = query[1];
        
        // Check the number of same parity pairs in the range
        int sameParityCount = sameParityPrefix[to] - sameParityPrefix[from];
        
        // If there are any same parity pairs, the subarray is not special
        result.push_back(sameParityCount == 0);
    }
    
    return result;
    }
};