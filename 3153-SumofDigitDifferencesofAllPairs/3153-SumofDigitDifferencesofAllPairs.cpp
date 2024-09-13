class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
       int n = nums.size();
    if (n <= 1) return 0;
    
    string s = to_string(nums[0]);
    int d = s.size(); // number of digits
    vector<vector<int>> digitCount(d, vector<int>(10, 0));
    
    // Count the frequency of each digit in each position
    for (int num : nums) {
        string str = to_string(num);
        for (int i = 0; i < d; ++i) {
            digitCount[i][str[i] - '0']++;
        }
    }
    
   long long  totalDifferences = 0;
    
    // Calculate total digit differences using the counts
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                if (j != k) {
                    totalDifferences += digitCount[i][j] * digitCount[i][k];
                }
            }
        }
    }
    
    return totalDifferences / 2; 
    }
};