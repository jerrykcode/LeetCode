class Solution {
public:
    int totalNQueens(int n) {
        size = n;
        n_solutions = 0;
        queenCol = new int[size];
        queen(0);
        free(queenCol);
        return n_solutions;
    }
private:
    int size;
    int *queenCol; //The queen in the i-th row is in queenCol[i]-th column
    int n_solutions;
    void queen(int row);
    bool canPlaceQueen(int row, int col);
};

void Solution::queen(int row) {
    if (row == size) {
      n_solutions++;
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
