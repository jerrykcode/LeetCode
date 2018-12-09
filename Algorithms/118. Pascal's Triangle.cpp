class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        if (numRows == 0) return result;
        vector<int> row0(1);
        row0[0] = 1;
        result[0] = row0;
        if (numRows == 1) return result;
        vector<int> row1(2);
        row1[0] = row1[1] = 1;
        result[1] = row1;
        if (numRows == 2) return result;
        for (int i = 2; i < numRows; i++) {
            vector<int> row(i + 1);
            row[0] = 1;
            for (int j = 1; j < i; j++) { //1 ~ i - 1
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            row[i] = 1;
            result[i] = row;
        }
        return result;
    }
};