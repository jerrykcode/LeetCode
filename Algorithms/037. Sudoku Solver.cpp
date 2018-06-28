class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        init(board);
        dfs(board, 0, 0);
    }
private:
    bool **row_fill; //row_fill[i][j] means that if the number j exist in row i 
    bool **col_fill; //col_fill[i][j] means that if the number j exist in column i
    bool **box_fill; //box_fill[i][j] means that if the number j exist in box i
    int get_box_id(int row_idx, int col_idx);
    void init(vector<vector<char>>& board);
    bool dfs(vector<vector<char>>& board, int row_idx, int col_idx);
};

int Solution::get_box_id(int row_idx, int col_idx) {
    return (row_idx / 3) * 3 + col_idx / 3;
}

void Solution::init(vector<vector<char>>& board) {
    row_fill = new bool * [9];
    col_fill = new bool * [9];
    box_fill = new bool * [9];
    for (int i = 0; i < 9; i ++) {
        row_fill[i] = new bool[10];
        col_fill[i] = new bool[10];
        box_fill[i] = new bool[10];
        for (int j = 0; j < 10; j ++)
            row_fill[i][j] = col_fill[i][j] = box_fill[i][j] = false;
    }
    for (int i = 0; i < 9; i ++)
        for (int j = 0; j < 9; j ++) {
            if (board[i][j] == '.') continue;
            int num = (int)board[i][j] - '0';
            row_fill[i][num] = true;
            col_fill[j][num] = true;
            box_fill[get_box_id(i, j)][num] = true;
        }
}

bool Solution::dfs(vector<vector<char>>& board, int row_idx, int col_idx) {
    //Find next empty cell
    int flag = 0;
    for (int i = row_idx; i < 9; i ++) {
        flag = 0;
        for (int j = 0; j < 9; j ++) {
            if (i == row_idx && j < col_idx) continue;
            if (board[i][j] == '.') {
                row_idx = i;
                col_idx = j; // [row_idx][col_idx] is empty cell
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    if (!flag) return true; //No empty cell exist, Sudoku solved
    for (int i = 1; i <= 9; i ++) {
        //if the number i already existed in the row or column or the box of the empty cell
        if (row_fill[row_idx][i] || col_fill[col_idx][i] || box_fill[get_box_id(row_idx, col_idx)][i]) continue;
        row_fill[row_idx][i] = col_fill[col_idx][i] = box_fill[get_box_id(row_idx, col_idx)][i] = true;
        board[row_idx][col_idx] = i + '0';
        bool solved = false;
        if (col_idx + 1 <= 9) 
            solved = dfs(board, row_idx, col_idx + 1);
        else
            solved = dfs(board, row_idx + 1, 0);
        if (solved) return true;
        row_fill[row_idx][i] = col_fill[col_idx][i] = box_fill[get_box_id(row_idx, col_idx)][i] = false;
        board[row_idx][col_idx] = '.';
    }
    return false;
}
