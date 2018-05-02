class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2]; //init
        for (int i = 0; i < nums.size() - 2; i ++) {
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == target) return sum;
                if (sum < target)
                    start++;
                else end--;
                if (abs(sum - target) < abs(closest - target))
                    closest = sum;
            }
        }
        return closest;
    }
};
