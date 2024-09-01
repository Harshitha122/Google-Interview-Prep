class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int seen1[9][9]={0};
        int seen2[9][9]={0};
        int seen3[9][9]={0};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                int num=board[i][j]-'0'-1;
                int k=(i/3)*3+(j/3);
                if(seen1[i][num] || seen2[j][num]|| seen3[k][num]){
                    return false;
                }
                seen1[i][num]=seen2[j][num]=seen3[k][num]=1;
                }
            }
        }
        return true;
    }
};