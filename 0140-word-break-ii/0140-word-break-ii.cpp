class Solution {
public:
void solve(string s,vector<string> &res,vector<string> &temp,unordered_set<string> &st){
    if(s.length()==0){
        string str="";
        for(auto it:temp){
            str+=it+" ";
        }
        str.pop_back();
        res.push_back(str);
        return;
    }
    for(int i=0;i<s.length();i++){
        string x=s.substr(0,i+1);
        if(st.count(x)){
            temp.push_back(x);
            solve(s.substr(i+1),res,temp,st);
            temp.pop_back();
        }
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        vector<string> temp;
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        solve(s,res,temp,st);
        return res;
    }
};