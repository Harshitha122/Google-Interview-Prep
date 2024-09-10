class Solution {
public:
    bool ispalindrome(string s){
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void partition(int i,string s,vector<string> &ans,vector<vector<string>> &res){
        if(i==s.length()){
            res.push_back(ans);
        }
        for(int j=i;j<s.length();j++){
            if(ispalindrome(s.substr(i,j-i+1))){
                ans.push_back(s.substr(i,j-i+1));
                partition(j+1,s,ans,res);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>> res;
        vector<string> ans;
        partition(0,s,ans,res);
        return res;
    }
};