class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> permutation;
        dfs(nums, permutation);
        vector<vector<int>> permutations;
        for (auto it = result.begin(); it != result.end(); it ++)
            permutations.push_back(*it);
        return permutations;
    }
private:
    map<int, int> collected;
    set<vector<int>> result;
    void dfs(vector<int>& nums, vector<int>& permutation);
};

void Solution::dfs(vector<int>& nums, vector<int>& permutation) {
    if (nums.size() == 0) return;
    if (permutation.size() == nums.size()) {
        result.insert(permutation);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (!collected[i]) {
            collected[i] = true;
            permutation.push_back(nums[i]);        
            dfs(nums, permutation);
            permutation.pop_back();
            collected[i] = false;
        }
    }
}
