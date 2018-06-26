class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, size = nums.size(), right = size - 1;
        vector<int> range;
        //Binary Search
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) { 
                range.push_back(leftRange(nums, left, mid, target)); //Find left range
                range.push_back(rightRange(nums, mid, right, target)); //Find right range
                return range;
            }
            else if (nums[mid] > target)
                right = mid - 1;
            else left = mid + 1;
        }
        for (int i = 0; i < 2; i ++) range.push_back(-1);
        return range;
    }
private:
    /* Returns the left range of the sequence. */
    int leftRange(vector<int>& nums, int left, int right, int target);
    /* Returns the right range of the sequence. */
    int rightRange(vector<int>& nums, int left, int right, int target);
};

int Solution::leftRange(vector<int>& nums, int left, int right, int target) {
    while (left <= right) {
       int mid = (left + right) / 2;
        if (nums[mid] == target) {
            if (mid - 1 >= left && nums[mid - 1] != target) return mid;
            right = mid - 1;
        } else {
            if (mid + 1 <= right && nums[mid + 1] == target) return mid + 1;
            left = mid + 1;
        }
    }
    return left;
}

int Solution::rightRange(vector<int>& nums, int left, int right, int target) {
    while (left <= right) {
       int mid = (left + right) / 2;
        if (nums[mid] == target) {
            if (mid + 1 <= right && nums[mid + 1] != target) return mid;
            left = mid + 1;
        } else {
            if (mid - 1 >= left && nums[mid - 1] == target) return mid - 1;
            right = mid - 1;
        }
    }
    return right;
}
