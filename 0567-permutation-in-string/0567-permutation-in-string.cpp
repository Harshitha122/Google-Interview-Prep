class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        if(s1.length()>s2.length()){
            return false;
        }
        for(int i=0;i<s1.length();i++){
            mp1[s1[i]-'a']++;
        }
        for(int i=0;i<s1.length();i++){
            mp2[s2[i]-'a']++;
        }        
        if(mp1==mp2){
            return true;
        }
        int n1=s1.length();
        int n2=s2.length();
        for(int i=n1;i<n2;i++){
            mp2[s2[i]-'a']++;
            mp2[s2[i-n1]-'a']--;
            if(mp1==mp2){
                return true;
            }
        }
        return false;
    }
};