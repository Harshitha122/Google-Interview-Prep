class Solution {
public:
    int maximumLength(string s) {
        int n=s.length();
         vector<vector<int>> map(26, vector<int>(n + 1, 0));
        int len=1;
        int res=-1;
        char pre=s[0];
        map[pre-'a'][1]=1;
        for(int i=1;i<n;i++){
            if(pre==s[i]){
                len++;
                map[s[i]-'a'][len]+=1;
                
            }
            else{
                len=1;
                map[s[i]-'a'][len]++;
                pre=s[i];
            }
        }
        for(int i=0;i<26;i++){
            int presum=0;
            for(int j=n;j>=1;j--){
                presum+=map[i][j];
                if(presum>=3){
                    res=max(res,j);
                 
                }
            }
        }
        return res;
    }
};