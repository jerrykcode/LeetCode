class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (haystack == "") return -1;
        if (haystack.size() < needle.size()) return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); i ++) {
            int j;
            for (j = 0; j < needle.size() && haystack[i + j] == needle[j]; j++);
            if (j == needle.size()) return i;
        }
        return -1;
    }
};
