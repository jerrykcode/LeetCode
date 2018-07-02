class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = 0;  //Last index can jump, initailized as 0
        for (int i = 0; i < nums.size(); i ++) {
            if (i > last) return false; //i is not reachable
            if (nums[i] + i > last) last = nums[i] + i;
            if (last >= nums.size() - 1) return true;
        }
        return false;
    }
};
