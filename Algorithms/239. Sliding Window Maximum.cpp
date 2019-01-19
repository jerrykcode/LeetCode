class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.size() == 0) return result;
        else if (nums.size() == 1) {
            result.push_back(nums[0]);
            return result;
        }
        int left = nums[0], midmax = nums[1];
        int midmax_index = 1;
        for (int i = k - 1; i >= 2; i--)
            if (nums[i] > midmax) {
                midmax = nums[i];
                midmax_index = i;
            }
        result.push_back(max(left, midmax));
        for (int i = 1; i < nums.size() - k + 1; i++) {
            result.push_back(max(midmax, nums[i + k - 1]));
            if (midmax_index == i) {
                midmax = nums[i + 1]; 
                midmax_index = i + 1;
                for (int j = i + k - 2; j >= i + 2; j--)
                    if (nums[j] > midmax) {
                        midmax = nums[j];
                        midmax_index = j;  
                    }
            }
            midmax = max(midmax, nums[i + k - 1]);
        }
        return result;
    }
};