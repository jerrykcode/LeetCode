class Solution {
public:
    int numDecodings(string s) {               
        if (s[0] == '0') return 0;
        int *dp = new int[s.length()];
        dp[0] = 1;
        for (int i = 1; i < s.length(); i++) {
            dp[i] = 0;
            if (s[i] != '0') dp[i] += dp[i - 1];
            if (s[i - 1] != '0') {
                int value = atoi((s.substr(i - 1, 2)).c_str());
                if (value >= 1 && value <= 26) {
                    if (i - 2 >= 0) dp[i] += dp[i - 2];
                    else dp[i] += 1;
                }
            }
        }
        int result = dp[s.length() - 1];
        free(dp);
        return result;
    }
};