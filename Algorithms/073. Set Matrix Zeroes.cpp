typedef vector<vector<int>>& Matrix;
class Solution {
public:
    void setZeroes(Matrix matrix) ;
private:
    void setZeroesRow(Matrix matrix,int row);
    void setZeroesCol(Matrix matrix, int col);
       
    int n_rows, n_cols;
    bool * rows;
    bool * cols;
};

void Solution::setZeroes(Matrix matrix) {
    n_rows = matrix.size();
    if (0 == n_rows) {
        return;
    }
    n_cols = matrix[0].size();
    if (0 == n_cols) {
        return;
    }
    rows = new bool[n_rows];
    memset(rows, false, n_rows * sizeof(bool));
    cols = new bool[n_cols];
    memset(cols, false, n_cols * sizeof(bool));
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            if (matrix[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    for (int r = 0; r < n_rows; r++) {
        if (rows[r]) {
            setZeroesRow(matrix, r);
        }
    }
    for (int c = 0; c < n_cols; c++) {
        if (cols[c]) {
            setZeroesCol(matrix, c);
        }
    }
    free(rows);
    rows = NULL;
    free(cols);
    cols = NULL;
}

void Solution::setZeroesRow(Matrix matrix, int row) {
    for (int i = 0; i < n_cols; i++) {
        matrix[row][i] = 0;
    }
}

void Solution::setZeroesCol(Matrix matrix, int col) {
    for (int i = 0; i < n_rows; i++) {
        matrix[i][col] = 0;
    }
}
