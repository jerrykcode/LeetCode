class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int **dp = new int*[2];
        for (int i = 0; i < 2; i++)
            dp[i] = new int[size];
        int max_num_index = 0;
		dp[0][0] = 1;
        for (int i = 1; i < size; i++) {
            dp[0][i] = nums[i] <= nums[0] ? 0 : 1;
            if (nums[i] > nums[max_num_index]) max_num_index = i;
        }
		int result = 1;
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < size; j++) {
				if (nums[i] > nums[j])
					dp[1][j] = dp[0][j];
				else if (i != j && nums[i] == nums[j])
					dp[1][j] = dp[0][j];
                else 
                    dp[1][j] = max(dp[0][j], dp[0][i] + 1);                                 
				if (dp[1][j] > result) result = dp[1][j];
            }        
            int *tmp = dp[0];
            dp[0] = dp[1];
            dp[1] = tmp;
        }       
        free(dp[0]);
        free(dp[1]);
        return result;
    }
};
