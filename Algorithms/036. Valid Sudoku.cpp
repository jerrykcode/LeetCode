class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int nRows = 9, nCols = 9;
        bool flag[10]; // 0 ~ 9
        //Test rows
        for (int i = 0; i < nRows; i ++) {
            fill(flag, flag + 10, false); 
            for (int j = 0; j < nCols; j ++) {
                if (board[i][j] == '.') continue;
                if (flag[(int)board[i][j] - '0']) return false; //repetition
                flag[(int)board[i][j] - '0'] = true;
            }
        }
        //Test columns
        for (int i = 0; i < nCols; i ++) {
            fill(flag, flag + 10, false);
            for (int j = 0; j < nRows; j ++) {
                if (board[j][i] == '.') continue;
                if (flag[(int)board[j][i] - '0']) return false; //repetition
                flag[(int)board[j][i] - '0'] = true;
            }
        }
        //Test 3x3 sub-boxes
        for (int i = 0; i < 3; i ++) 
            for (int j = 0; j < 3; j ++) {
                //[i][j] box
                fill (flag, flag + 10, false);
                int row = 3 * i, col = 3 * j;
                for (int r = 0; r < 3; r ++)
                    for (int c = 0; c < 3; c ++) {
                        if (board[row + r][col + c] == '.') continue; 
                        if (flag[(int)board[row + r][col + c] - '0']) return false; //repetition
                        flag[(int)board[row + r][col + c] - '0'] = true;
                    }
            }
        return true;
    }
};
