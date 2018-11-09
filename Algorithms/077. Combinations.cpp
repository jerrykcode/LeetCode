class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (!n || !k) return result;
        vector<int> combination;
        dfs(combination, n, k, 1);
        return result;
    }
private:
    vector<vector<int>> result;
    void dfs(vector<int>&combination, int n, int k, int start);
};

void Solution::dfs(vector<int>&combination, int n, int k, int start) {
    if (combination.size() == k) {
        result.push_back(combination);
        return;
    }
    for (int i = start; i <= n; i++) {
        combination.push_back(i);
        dfs(combination, n, k, i + 1);
        combination.pop_back();
    }
}