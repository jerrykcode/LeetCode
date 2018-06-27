class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return 0; 
        if (target < nums[0]) return 0;
        if (target > nums[size - 1]) return size;
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target) {
                left = mid + 1;    
                if (left > right) return left;
            }
            else {
                right = mid - 1;
                if (left > right) return right + 1; //Insert an element
            }
        }    
        return -1;
    }
};
