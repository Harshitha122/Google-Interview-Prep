class Solution {
public:
    int dp[1005][1005];
    int helper(int l,int r,vector<int> &piles){
        if(l==r-1)
            return max(piles[l],piles[r-1]);
        if(dp[l][r]!=-1)
            return dp[l][r];
        int left=piles[l]+max(helper(l+1,r-1,piles),helper(l+2,r,piles));
         int right=piles[r]+max(helper(l+1,r-1,piles),helper(l,r-2,piles));
        return dp[l][r]=max(left,right);
    }
    bool stoneGame(vector<int>& piles) {
        int l=0;
        int r=piles.size()-1;
        memset(dp,-1,sizeof(dp));
        int alex=helper(l,r,piles);
        int sum=0;
       
        for(auto x:piles){
            sum+=x;
        }
        return alex>(sum)/2;
    }
};