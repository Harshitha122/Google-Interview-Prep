class Solution {
public:
   /* int closedIsland(vector<vector<int>>& grid) {*/
    
    int r , c;
    
    void dfs(vector<vector<int>>& grid , int i , int j){
        if(i < 0 || j < 0 || j >= c || i >= r || grid[i][j] != 0) return;
        grid[i][j] = -1;
        dfs(grid , i - 1 , j);
        dfs(grid , i + 1 , j);
        dfs(grid , i , j - 1);
        dfs(grid , i , j + 1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        
        for(int i = 0;i < r;i++)    // this is for edge conneced zeroes
            for(int j = 0;j < c;j++)
                if((j == 0 || i == 0 || j == c-1 || i == r-1) && grid[i][j] == 0)
                    dfs(grid,i,j);
        
        int count = 0;
        for(int i = 0;i < r;i++)   // this is for Number of Closed zeroes
            for(int j = 0;j < c;j++)
                if(grid[i][j] == 0){
                    count++;
                    dfs(grid,i,j);
                }
        
        return count;
        
    }
};