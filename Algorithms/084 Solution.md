For every (*i*, *j*), *0 <= i < heights.size() and i <= j < heights.size()*, calculates the area form bar *i* to *j*. If heights[*i*] <= heights[*i - 1*], then there is no need to calculate the area of rectangles starts with bar *i*, because any rectangle starts with bar *i* can gain their area by starting with bar *i - 1*. When looking for the max area rectangle starts with bar *i*, an array *dp* is used . dp[*j*] means the height of the shortest bar from *i* to *j*, that is, the smallest value between heights[*i*] and heights[*j*]. ```dp[i] = heights[i]``` and ```dp[j] = min(dp[j - 1], heights[j])```. Area of rectangle from bar *i* to bar *j* can be calculated by ```dp[j] * (j - i + 1)```

```cpp
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
```