//参考：
//https://leetcode.com/problems/substring-with-concatenation-of-all-words/discuss/13658/Easy-Two-Map-Solution-(C++Java)
//Easy Two-Map Solution (C++/Java)

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        map<string, int> count;
        for (auto it = words.begin(); it != words.end(); it++)
            count[*it]++;
        int num = words.size();
        if (num == 0) return result;
        int word_len = words[0].length();
        for (int i = 0; i < s.length() - num * word_len + 1; i ++) {
            int flag = 0;
            map<string, int> occur_time;
            for (int j = 0; j < num; j ++) {
                string word = s.substr(i + j * word_len, word_len);                
                if (count.find(word) == count.end()) {
                    flag = 1;
                    break;
                }
                occur_time[word]++;
                if (occur_time[word] > count[word]) {
                    flag = 1;
                    break;
                }
            }
            if (flag) continue;
            result.push_back(i);
        }
        return result;
    }
};
