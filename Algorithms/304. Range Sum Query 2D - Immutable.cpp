class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix);
    ~NumMatrix();
    
    int sumRegion(int row1, int col1, int row2, int col2);
private:
	bool matrixNotEmpty;
    int **sum;
    int nRows;
    int nCols;
};

NumMatrix::NumMatrix(vector<vector<int>> matrix) : nRows(matrix.size()), nCols(nRows != 0 ? matrix[0].size() : 0), matrixNotEmpty(false) {
    if (nRows == 0 || nCols == 0) return;
	matrixNotEmpty = true;
    sum = new int *[nRows];
    for (int i = 0; i < nRows; i++)
        sum[i] = new int[nCols];
    for (int i = 0; i < nRows; i++) {
        sum[i][0] = matrix[i][0];
        for (int j = 1; j < nCols; j++) 
            sum[i][j] = sum[i][j - 1] + matrix[i][j];           
		if (i > 0) {
			for (int j = 0; j < nCols; j++)
				sum[i][j] += sum[i - 1][j];
		}
    }	
}

NumMatrix::~NumMatrix() {
	if (matrixNotEmpty) {
		for (int i = 0; i < nRows; i++)
			free(sum[i]);
		free(sum);
	}
}

int NumMatrix::sumRegion(int row1, int col1, int row2, int col2) {
    if (row1 < 0 || row1 >= nRows || row2 < 0 || row2 >= nRows) return 0;
    if (col1 < 0 || col1 >= nCols || col2 < 0 || col2 >= nCols) return 0;
    int a = row1 - 1 >= 0 ? sum[row1 - 1][col2] : 0;
    int b = col1 - 1 >= 0 ? sum[row2][col1 - 1] : 0;
    int c = (row1 - 1 >= 0 && col1 - 1 >= 0) ? sum[row1 - 1][col1 - 1] : 0;
    return sum[row2][col2] - a - b + c;
}
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */