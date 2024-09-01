class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k==0){
            return 0;
        }
        int n=s.length();
        int i=0,j=0;
        int len=0;
        unordered_map<char,int> mp;
        while(i<n){
             mp[s[i]]++;
            if(mp.size()>k){
                while(j<i && mp.size()>k){
                    mp[s[j]]--;
                    if(mp[s[j]]==0){
                        mp.erase(s[j]);
                    }
                    j++;
                }
            }
            len=max(len,i-j+1);
            i++;
            
        }
        return len;
    }
};
