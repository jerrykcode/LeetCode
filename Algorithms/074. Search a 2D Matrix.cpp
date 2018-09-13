#define _2D_TO_1D_INDEX(row, col) row * nCols + col
#define _1D_TO_2D_INDEX(index, row, col) row = index / nCols; col = index % nCols 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        nRows = matrix.size();
        if (!nRows) return false;
        nCols = matrix[0].size();
        if (!nCols) return false;
        int start = _2D_TO_1D_INDEX(0, 0);
        int end = _2D_TO_1D_INDEX((nRows - 1), (nCols - 1));
        return binarySearch(matrix, target, start, end);        
    }
private:
    int nRows;
    int nCols;
    bool binarySearch(vector<vector<int>>& matrix, int target, int start, int end);
};

bool Solution::binarySearch(vector<vector<int>>& matrix, int target, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        int mid_row, mid_col;
        _1D_TO_2D_INDEX(mid, mid_row, mid_col);
        int mid_val = matrix[mid_row][mid_col];
        if (mid_val == target) {
            return true;
        } else if (mid_val > target) {
            end = mid - 1;
        } else {//mid_val < target
            start = mid + 1;
        }
    }
    return false;
}
