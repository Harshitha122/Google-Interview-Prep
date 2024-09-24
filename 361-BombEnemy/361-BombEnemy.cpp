class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int i, j, row = grid.size(), col, result, head, tail;
        if(row == 0 || (col = grid[0].size()) == 0)
            return 0;
        vector<vector<int> > count(row, vector<int>(col, 0));
        for(i = 0; i < row; i++) {
            for(head = tail = j = 0; j < col; j++) {
                count[i][j] = grid[i][j] != '0' ? 0 : (count[i][j] + head);
                count[i][col - 1 - j] = grid[i][col - 1 - j] != '0' ? 0 : (count[i][col - 1 - j] + tail);
                head = grid[i][j] == 'W' ? 0 : (head + (grid[i][j] == 'E' ? 1 : 0));
                tail = grid[i][col - 1 - j] == 'W' ? 0 : (tail + (grid[i][col - 1 - j] == 'E' ? 1 : 0));
            }
        }
        for(j = 0; j < col; j++) {
            for(head = tail = i = 0; i < row; i++) {
                count[i][j] = grid[i][j] != '0' ? 0 : (count[i][j] + head);
                count[row - 1 - i][j] = grid[row - 1 - i][j] != '0' ? 0 : (count[row - 1 - i][j] + tail);
                head = grid[i][j] == 'W' ? 0 : (head + (grid[i][j] == 'E' ? 1 : 0));
                tail = grid[row - 1 - i][j] == 'W' ? 0 : (tail + (grid[row - 1 - i][j] == 'E' ? 1 : 0));
            }
        }
        for(i = result = 0; i < row; i++) {
            for(j = 0; j < col; j++) {
                result = max(result, count[i][j]);
            }
        }
        return result;
    }
};