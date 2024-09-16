class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res=target[0];
        for(int i=1;i<target.size();i++){
            res+=max(target[i]-target[i-1],0);
        }
        return res;
    }
};