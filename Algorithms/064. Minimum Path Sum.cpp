class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        if (!n) return 0;
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < n; j ++) {
                int preSum;
                if (i - 1 >= 0 && j - 1 >= 0) preSum = min(grid[i - 1][j], grid[i][j - 1]);
                else if (i - 1 >= 0 || j - 1 >= 0) preSum = (i - 1 >= 0) ? grid[i - 1][j] : grid[i][j - 1];
                else preSum = 0;
                grid[i][j] += preSum;
            }
        return  grid[m - 1][n - 1];
    }
};
