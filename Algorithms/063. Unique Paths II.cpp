class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (!m) return 0;
        int n = obstacleGrid[0].size();
        if (!n) return 0;
        int **dp = new int*[m]; //dp[i][j] = number of paths from (0, 0) to (i, j)
        for (int i = 0; i < m; i ++) {
            dp[i] = new int[n];
            memset(dp[i], 0, n * sizeof(int));
        }
        dp[0][0] = obstacleGrid[0][0] ? 0 : 1;
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < n; j ++) {
                if (i || j) {
                    dp[i][j] = obstacleGrid[i][j] ? 0 : ((i - 1 >= 0) ? dp[i - 1][j] : 0) + ((j - 1 >= 0) ? dp[i][j - 1] : 0);
                }                
            }
        int result = dp[m - 1][n - 1];
        free(dp);
        return result;
    }
};
