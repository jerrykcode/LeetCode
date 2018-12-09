class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if (rowIndex == 0) {
            result.push_back(1);
            return result;
        }     
        result.push_back(1);
        result.push_back(1);
        if (rowIndex == 1) return result;     
        vector<int> preRow;
        int row = 1;
        while (row < rowIndex) {
            preRow = result;
            result.clear();
            row++;
            result.push_back(1);
            for (int i = 1; i < row; i++)
                result.push_back(preRow[i - 1] + preRow[i]);
            result.push_back(1);            
        }
        return result;
    }
};