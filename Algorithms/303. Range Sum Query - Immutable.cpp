class NumArray {
public:
    NumArray(vector<int> nums);
    
    int sumRange(int i, int j);
    
private:
    int *sum;
    int n;
};

NumArray::NumArray(vector<int> nums) :n(nums.size()) {
    if (n == 0) return;
    sum = new int[n];
    sum[0] = nums[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + nums[i];
}

int NumArray::sumRange(int i, int j) {
    if (i < 0 || i >= n) return 0;
    if (j < 0 || j >= n) return 0;
    return i > 0 ? sum[j] - sum[i - 1] : sum[j];
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */