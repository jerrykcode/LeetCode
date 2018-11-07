class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        if (size == 0) return 0;
        int maxArea = 0;
        for (int i = 0; i < size; i++) {
            if (i > 0 && heights[i] <= heights[i - 1]) continue;
            int *dp = new int[size];
            dp[i] = heights[i];
            if (dp[i] > maxArea) maxArea = dp[i];
            for (int j = i + 1; j < size; j++) {
                dp[j] = heights[j] < dp[j - 1] ? heights[j] : dp[j - 1];
                if (dp[j] * (j - i + 1) > maxArea) maxArea = dp[j] * (j - i + 1);
            }
            free(dp);
        }
        return maxArea;
    }
};