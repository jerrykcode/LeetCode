class Solution {
public:
    int lengthOfLastWord(string s) {
        while (*(s.end() - 1) == ' ') s.erase(s.end() - 1);
        int size = s.size();
        if (size == 0) return 0;        
        int len = 0;
        for (int i = size - 1; i >= 0; i --) {
            if (s[i] == ' ') break;
            len ++;
        }
        return len;
    }
};
