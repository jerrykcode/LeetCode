class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word == "") return true;
        int nRows = board.size();
        if (nRows == 0) return false;
        int nCols = board[0].size();
        if (nCols == 0) return false;
        bool **collected = new bool *[nRows];
        for (int i = 0; i < nRows; i++)
            collected[i] = new bool[nCols];
        for (int row = 0; row < nRows; row++)
            for (int col = 0; col < nCols; col++) {
                if (board[row][col] == word[0]) {
                    for (int i = 0; i < nRows; i++) fill(collected[i], collected[i] + nCols, false);
                    collected[row][col] = true;
                    if (dfs(board, row, col, collected, word, 0)) return true;
                }
            }
        for (int i = 0; i < nRows; i++) free(collected[i]);
        free(collected);
        return false;
    }
private :
    bool dfs(vector<vector<char>>& board, int row, int col, bool **collected, string word, int idx);
};

bool Solution::dfs(vector<vector<char>>& board, int row, int col, bool **collected, string word, int idx) {     
    if (idx == word.size() - 1) return true;
    if (row - 1 >= 0 && !collected[row - 1][col] && board[row - 1][col] == word[idx + 1]) {
        collected[row - 1][col] = true;
        if (dfs(board, row - 1, col, collected, word, idx + 1)) return true;
        collected[row - 1][col] = false;
    }
    if (row + 1 < board.size() && !collected[row + 1][col] && board[row + 1][col] == word[idx + 1]) {
        collected[row + 1][col] = true;
        if (dfs(board, row + 1, col, collected, word, idx + 1)) return true;
        collected[row + 1][col] = false;
    }
    if (col - 1 >= 0 && !collected[row][col - 1] && board[row][col - 1] == word[idx + 1]) {
        collected[row][col - 1] = true;
        if (dfs(board, row, col - 1, collected, word, idx + 1)) return true;
        collected[row][col - 1] = false;
    }
    if (col + 1 < board[0].size() && !collected[row][col + 1] && board[row][col + 1] == word[idx + 1]) {
        collected[row][col + 1] = true;
        if (dfs(board, row, col + 1, collected, word, idx + 1)) return true;
        collected[row][col + 1] = false;
    }
    return false;
}
