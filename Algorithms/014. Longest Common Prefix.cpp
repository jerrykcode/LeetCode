class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0]; //Initial prefix
        int len = prefix.length(); //Initial prefix length
        for (int i = 1; i < strs.size(); i ++) {
            int j;
            for (j = 0; j < len && j < strs[i].length() && prefix[j] == strs[i][j]; j ++);
            len = j;
            if (len == 0) return "";
        }
        return prefix.substr(0, len);
    }
};
