class Solution {
public:
    bool canPermutePalindrome(string s) {
         int dict[256] = {0};
    for (auto c: s)
        dict[c]++;
    int cnt = 0;
    for (int i=0; i<256; i++){
        if (dict[i] % 2 != 0)   cnt++;
    }
    
    return cnt<=1;
    }
};