class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int last = 0;
		int lastValue;
		for (int i = 0; i < nums.size(); i++) {
			if (i - 2 >= 0) {
				if (last - 1 == i - 2) {
					if (nums[i] == lastValue) continue;
				}
				else {
					if (nums[i] == nums[i - 2]) continue;
				}
			}
			lastValue = nums[last];
			nums[last++] = nums[i];
		}
		return last;
	}
};