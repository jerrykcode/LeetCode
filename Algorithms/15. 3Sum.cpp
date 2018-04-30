
/* 本题思路参考 @codingtmd (https://github.com/codingtmd) 的 《编程谜题》*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //寻找 a + b + c = 0
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        int len = nums.size(); //以下的len不能换成nums.size(), 因为vector<T>::size()的返回值是unsigned, 若传递进一个空vector, 则nums.size() = 0，
                                //nums.size() - 1变为一个非常大的数
                                 //(见https://stackoverflow.com/questions/47947956/reference-binding-to-null-pointer-of-type-value-type?rq=1)
        for (int i = 0; i <= len - 3; i ++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; //防止重复
            int target = 0 - nums[i]; //若a = nums[i], 则问题变为寻找 b + c = 0 - a
            int start = i + 1, end = len - 1; //寻找范围从 i + 1 到最后
            while (start < end) {
                int sum = nums[start] + nums[end];
                if (sum < target)
                    start++;
                else if (sum > target)
                    end--;
                else { //sum == target
                    triplets.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    while (start < end && nums[start] == nums[start - 1]) start++; //防止重复
                    while (start < end && nums[end] == nums[end + 1]) end--;
                }
            } //while
        } //for
        return triplets;
    }
};
