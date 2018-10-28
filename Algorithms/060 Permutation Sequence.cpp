class Solution {
public:
    string getPermutation(int n, int k) {
        count = 0;
        vector<int> seq;
        bool *collected = new bool[n + 1]; //[0, n], [1, n] in use
        fill(collected, collected + n + 1, false);
        dfs(seq, collected, n, k);
        free(collected);
        stringstream result;
        for (int i = 0; i < seq.size(); i++) 
            result << seq[i];
        return result.str();
    }
    
private:
    int count;
    bool dfs(vector<int>& seq, bool *collected, int n, int k);
};

bool Solution::dfs(vector<int>& seq, bool *collected, int n, int k) {
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!collected[i]) {
            flag = false;
            seq.push_back(i);
            collected[i] = true;
            if (dfs(seq, collected, n, k)) return true;
            seq.pop_back();
            collected[i] = false;
        }
    }
    if (flag) {
        count++;
        if (count == k) return true;
    }
    return false;
}
