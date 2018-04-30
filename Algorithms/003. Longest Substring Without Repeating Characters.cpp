class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int len = 0, mlen = 0;
		int flag[256];
		fill(flag, flag + 256, -1);
		for (int i = 0; i < s.length(); i ++) {
			if (flag[s[i]] == -1) {
				len++;
				flag[s[i]] = i;
			} else {
				if (len > mlen) mlen = len;
				len = 0;
				i = flag[s[i]];
				fill(flag, flag + 256, -1);
			}
		}
		if (len > mlen) mlen = len;
		return mlen;
	}
};
