class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        queenCol = new int[size];
        queen(0);
        free(queenCol);
        return solution;
    }
private:
    int size;
    int *queenCol; //The queen in the i-th row is in queenCol[i]-th column
    vector<vector<string>> solution;
    void queen(int row);
    bool canPlaceQueen(int row, int col);
};

void Solution::queen(int row) {
    if (row == size) {
        vector<string> checkerboard;
        for (int i = 0; i < size; i++) {
            string rowstr = "";
            for (int j = 0; j < size; j++)
                rowstr += (queenCol[i] == j ? 'Q' : '.');
            checkerboard.push_back(rowstr);
        }
        solution.push_back(checkerboard);
    }
    for (int col = 0; col < size; col++) {
        if (canPlaceQueen(row, col)) {
            queenCol[row] = col;
            queen(row + 1);
        }
    }
}

bool Solution::canPlaceQueen(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queenCol[i] == col) return false;
        if (queenCol[i] - col == i - row || queenCol[i] - col == row - i) return false;
    }
    return true;
}
