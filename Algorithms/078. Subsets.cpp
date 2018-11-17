class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<int> index_set;
        dfs(nums, subset, index_set);
        return result;
    }
private:
    void dfs(vector<int>& nums, vector<int>& subset, vector<int>& index_set);
    vector<vector<int>> result;
};

void Solution::dfs(vector<int>& nums, vector<int>& subset, vector<int>& index_set) {
    result.push_back(subset);
    for (int i = (index_set.empty() ? 0 : index_set[index_set.size() - 1] + 1); i < nums.size(); i++) {
        subset.push_back(nums[i]);
        index_set.push_back(i);
        dfs(nums, subset, index_set);
        subset.pop_back();
        index_set.pop_back();
    }
}