class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int index = 0;
        //比较每个元素与nums[index]
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == nums[index]) continue;
            //nums[i] != nums[index]
            if (i - index > 1) nums[index + 1] = nums[i]; //若i与index间隔超过1，则用nums[i]覆盖nums[index + 1]
            index++;
        }
        return index + 1;
    }
};
