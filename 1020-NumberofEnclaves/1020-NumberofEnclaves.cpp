class Solution {
public:
vector<vector<int>> dis={{-1,0},{1,0},{0,1},{0,-1}};
void dfs(int x,int y,int m, int n,vector<vector<int>> &vis,vector<vector<int>> &grid){
    vis[x][y]=1;
   for(int i=0;i<4;i++){
        int nx=x+dis[i][0];
        int ny=y+dis[i][1];
        if(nx<0 || nx>=m || ny<0 || ny>=n || grid[nx][ny]==0 || vis[nx][ny]==1){
            continue;
        }
        else{
            dfs(nx,ny,m,n,vis,grid);
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,m,n,vis,grid);
            }
            if(!vis[i][n-1]&& grid[i][n-1]==1){
                dfs(i,n-1,m,n,vis,grid);
            }
        }
        for(int j=0;j<n;j++){
            if(!vis[0][j]&&grid[0][j]==1){
                dfs(0,j,m,n,vis,grid);
            }
            if(!vis[m-1][j]&&grid[m-1][j]==1){
                dfs(m-1,j,m,n,vis,grid);
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&& grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};