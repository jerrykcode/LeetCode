//递归太慢，每个字符向两边扩展求回文子串， 参考了@liuchuo的解法：https://www.liuchuo.net/archives/3186
class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "") return s;
        string result = s.substr(0, 1);
        for (int i = 0; i < s.length() - 1; i ++) {
            string tmp = expand(s, i, i);
            if (tmp.length() > result.length()) result = tmp;
            tmp = expand(s, i, i + 1); 
            if (tmp.length() > result.length()) result = tmp;
        }
        return result;
    }
    
private:
    string expand(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};
