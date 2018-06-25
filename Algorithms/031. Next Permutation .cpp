//  参考Reference: https://leetcode.com/problems/next-permutation/solution/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0) return;
        int i = increase(nums);
        if (i == -1) {//The nums is in descending order
            reverse(nums, 0); //Reverse into ascending order
            return;
        }
        int j = largerNum(nums, i);
        swap(nums, i, j);
        reverse(nums, i + 1);
    }
private:
    /* Find the first pair from right that nums[i - 1] < nums[i] and returns (i - 1). */
    int increase(vector<int>& nums);
    
    /* Returns the index of the number in nums from index + 1 to its end which just larger 
       than nums[index]*/
    int largerNum(vector<int>& nums, int index);

    /* Swap 2 numbers. */
    void swap(vector<int>& nums, int i, int j);
    
    /* Reverse the nums vector form index to its end. In this case from index to its end, the
       vector nums is always descending and this method can reverse it into ascending order.*/
    void reverse(vector<int>& nums, int index);
};

//Implementation

int Solution::increase(vector<int>& nums) {
    int size = nums.size();    
    for (int i = size - 1; i > 0; i --)
        if (nums[i - 1] < nums[i])
            return i - 1;
    return -1;
}

int Solution::largerNum(vector<int>& nums, int index) {
    int size = nums.size();
    for (int i = size - 1; i >= index + 1; i --)
        if (nums[i] > nums[index])
            return i;
    return -1;
}

void Solution::swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void Solution::reverse(vector<int>& nums, int index) {
    int i = index;
    int size = nums.size(), j = size - 1;
    while (i < j)    
        swap(nums, i++, j--); //First swap (i, j) then i ++, j--
}
