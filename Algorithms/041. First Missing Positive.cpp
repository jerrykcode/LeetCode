class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = (int)nums.size();
		int firstPositive = 0;
		for (int i = 0; i < n; i++)
			if (nums[i] > 0) {
				firstPositive = nums[i];
				break;
			}
		if (firstPositive == 0) return 1;
		for (int i = 0; i < n; i++)
			if (nums[i] <= 0) nums[i] = firstPositive;
		for (int i = 0; i < n; i++) {
			int index = nums[i] > 0 ? nums[i] : -nums[i];
			if (index <= n) {
				if (index == n) index = 0;
				if (nums[index] > 0) nums[index] *= -1;
			}
		}
		for (int i = 1; i < n; i++)
			if (nums[i] > 0) return i;
		return nums[0] > 0 ? n : n + 1;
	}
};