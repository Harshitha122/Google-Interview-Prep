class Solution {
public:
vector<vector<int>> dis={{-1,0},{1,0},{0,1},{0,-1}};
void dfs(int x, int y, int m, int n,vector<vector<int>> &vis, vector<vector<char>> &board){
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+dis[i][0];
        int ny=y+dis[i][1];
        if(nx<0 || nx>=m || ny<0 || ny>=n || board[nx][ny]=='X' || vis[nx][ny]==1){
            continue;
        }
        else{
            dfs(nx,ny,m,n,vis,board);
        }
    }

}
void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m+1,vector<int> (n+1,0));
        for(int i=0;i<m;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,m,n,vis,board);
            }
            if(!vis[i][n-1]&& board[i][n-1]=='O'){
                dfs(i,n-1,m,n,vis,board);
            }
        }
        for(int j=0;j<n;j++){
            if(!vis[0][j]&& board[0][j]=='O'){
                dfs(0,j,m,n,vis,board);
            }
            if(!vis[m-1][j] && board[m-1][j]=='O'){
                dfs(m-1,j,m,n,vis,board);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
}
};