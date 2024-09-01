class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0,r=n-1,t=0,b=m-1;
        int k=0;
        while(l<=r && t<=b){
            for(int i=l;i<=r;i++){
                res.push_back(matrix[t][i]);
            }
            t++;
            for(int j=t;j<=b;j++){
                res.push_back(matrix[j][r]);
            }
            r--;
            if(t<=b){
            for(int j=r;j>=l;j--){
                res.push_back(matrix[b][j]);
            }

            b--;
            }
            if(l<=r){

            for(int j=b;j>=t;j--){
                res.push_back(matrix[j][l]);
            }
            l++;
            }
            
        }
        return res;
    }
};