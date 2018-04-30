class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max = 0, area = 0;
        while (left < right) {
            area = getAera(left, height[left], right, height[right]);
            max = max > area ? max : area;
            if (height[left] < height[right]) left++;
            else right--;
        }
        return max;
    }
private:
    int getAera(int x0, int h0, int x1, int h1) {
        return (x1 - x0) * min(h0, h1);
    }
};
