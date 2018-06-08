class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> group;
        for (int i = 0; i < strs.size();  i ++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            group[tmp].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for (auto it = group.begin(); it != group.end(); it ++)
            result.push_back(it->second);
        return result;
    }
};
