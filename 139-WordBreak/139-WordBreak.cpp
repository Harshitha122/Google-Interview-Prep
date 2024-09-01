class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0)
             return 0;
        int n=s.size();
        vector<int> dp(n+1,0);
        unordered_set<string> dict;
        for(auto x:wordDict)
            dict.insert(x);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    string temp=s.substr(j,(i-j));
                    if(dict.find(temp)!=dict.end()){
                        dp[i]=1;
                    }
                }
            }
        }
        return dp[n];
    }
};