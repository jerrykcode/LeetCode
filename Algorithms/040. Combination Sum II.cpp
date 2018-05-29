class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) ;
private:
    vector<vector<int>> result;
    set<vector<int>> tmp_result; //去重
    vector<int> candidates;
    int target;
    void dfs(vector<int>& set, int setSum, int index);
};

vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    this->candidates = candidates;
    this->target = target;
    vector<int> set;
    dfs(set, 0, -1); //从-1开始， 参考 https://www.liuchuo.net/archives/3269
    for (auto it = tmp_result.begin(); it != tmp_result.end(); it ++)
        result.push_back(*it);
    return result;
}

void Solution::dfs(vector<int>& set, int setSum, int index) {
    if (setSum == target) {
        tmp_result.insert(set);
        return;
    }
    if (setSum > target)
        return;
    for (int i = index + 1; i < candidates.size(); i ++) {
        set.push_back(candidates[i]);        
        dfs(set, setSum + candidates[i], i);
        set.pop_back();
    }
}
