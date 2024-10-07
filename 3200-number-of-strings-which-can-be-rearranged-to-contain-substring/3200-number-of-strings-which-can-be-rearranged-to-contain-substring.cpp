class Solution {
public:
    long long mod= 1e9+7;
    long long dp[100001][3][2][2];
    long long find(int index, int n, int e, int l, int t){
        if(index==n){
            //If the criteria is met, then return 1 else return 0

            if(e>=2 && l>=1 && t>=1)return 1;
            else return 0;
        }

        //If we have a precomputed answer
        if(dp[index][e][l][t]!=-1)return dp[index][e][l][t];

        //Initializing variable as zero
        long long pick=0;

        //Checking out each possibility from 'a' to 'z' with a loop
        for(int i=0;i<26;i++){

            if(i==4 && e<2){
                //If we encounter an 'e' and the variable has value less than 2, then increment it.

                pick= (pick +find(index+1,n,e+1,l,t))%mod;
            }

            else if(i==11 && l<1){
                //If we encounter an 'l' and the variable has value less than 1, then increment it.

                pick= (pick +find(index+1,n,e,l+1,t))%mod;
            }
            else if(i==19 && t<1){
                //If we encounter an 't' and the variable has value less than 1, then increment it.

                pick= (pick +find(index+1,n,e,l,t+1))%mod;
            }
            //Otherwise, just loop forward adding this possibility of i.
            else pick= (pick +find(index+1,n,e,l,t))%mod;
            
        }

        //Finally return the sum of all valid possibilities
        return dp[index][e][l][t] = pick;
        
    }
    int stringCount(int n) {
        memset(dp,-1,sizeof(dp));
        return (int)(find(0,n,0,0,0)%mod);
    }
};