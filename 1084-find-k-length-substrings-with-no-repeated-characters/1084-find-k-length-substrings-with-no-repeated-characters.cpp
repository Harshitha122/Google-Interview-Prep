class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if (k > 26)
            return 0;
        
        int answer = 0;
        int n = s.size();
        int left = 0, right = 0;
        int freq[26] = {0};
        
        while (right < n) {
            freq[s[right] - 'a']++;
            while (freq[s[right] - 'a'] > 1) {
                freq[s[left] - 'a']--;
                left++;
            }
            if (right - left + 1 == k) {
                answer++;
                freq[s[left] - 'a']--;
                left++;
            }
            right++;
        }
        
        return answer;
    }
};