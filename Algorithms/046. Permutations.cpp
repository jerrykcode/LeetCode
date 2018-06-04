class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> permutation;
        dfs(nums, permutation);
        return result;
    }
private:
    vector<vector<int>> result;
    map<int, bool> collected;
    void dfs(vector<int>& nums, vector<int>& permutation);
};

void Solution::dfs(vector<int>& nums, vector<int>& permutation) {
    if (permutation.size() == nums.size()) {
        result.push_back(permutation);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
        if (!collected[nums[i]]) {
            permutation.push_back(nums[i]);
            collected[nums[i]] = true;
            dfs(nums, permutation);
            permutation.pop_back();
            collected[nums[i]] = false;
        }
}
