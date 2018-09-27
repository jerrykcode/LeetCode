class Solution {
public:
    int jump(vector<int>& nums) {
        
	int n = nums.size();
	int *dist = new int[n];
	fill(dist, dist + n, 0);
	int lastIndex = 0;
	for (int i = 0; i < n; i++) {
			if (i + nums[i] <= lastIndex) continue;
        int j;
        for (j = lastIndex + 1; j <= i + nums[i] && j < n; j++) {
			dist[j] = dist[i] + 1;
		}
		lastIndex = j - 1;
        if (lastIndex >= n - 1) break;
	}
	int result = dist[n - 1];
	free(dist);
    return result;
    }
};
