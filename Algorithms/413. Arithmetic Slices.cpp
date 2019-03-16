class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sum = 0;
        int dp = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp = dp + 1;
                sum += dp;
            }
            else dp = 0;
        }
        return sum;
    }
};