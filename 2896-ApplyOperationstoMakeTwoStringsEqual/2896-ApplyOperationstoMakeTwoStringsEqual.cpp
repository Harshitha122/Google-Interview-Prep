
class Solution {
public:
    
    int dp[501][501];
    int solve(int l, int r, vector<int>&a,int x)
    {
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        
        int ans= min({ min(x, a[l+1]-a[l])+solve(l+2, r,a,x),  min(x, a[r]-a[l])+solve(l+1, r-1,a,x) , min(x, a[r]-a[r-1])+solve(l, r-2,a,x)});
        
        return dp[l][r]=ans;
    }
   
    int minOperations(string s1, string s2, int x) 
    {
        
        int n=s1.size();
        vector<int>a;
        for(int i=0; i<n; i++)
        {
            if(s1[i]!=s2[i])
            {
                a.push_back(i);
            }
        }
        if((int)a.size()%2) return -1;
        if(a.size()==0) return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,a.size()-1,a,x);
        
    }
};