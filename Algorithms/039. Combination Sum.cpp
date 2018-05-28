class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> set;
        dfs(set, candidates, 0, target, 0);
        return result;
    }
private:
    vector<vector<int>> result;
    void dfs(vector<int>& set, vector<int>& candidates, int setSum, int target, int index) {
        if (setSum == target) {
            result.push_back(set);
            return;
        }
        if (setSum > target)
            return;
        for (int i = index; i < candidates.size(); i ++) {
            set.push_back(candidates[i]);
            dfs(set, candidates, setSum + candidates[i], target, i);
            set.pop_back();
        }
    }
};
