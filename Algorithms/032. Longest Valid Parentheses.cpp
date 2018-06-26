//参考 Reference ： https://leetcode.com/problems/longest-valid-parentheses/solution/

class Solution {
public:
    int longestValidParentheses(string s) {
        int leftIncrement = 0, rightIncrement = 0, maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            s[i] == '(' ? leftIncrement++ : rightIncrement++;
            if (leftIncrement == rightIncrement)
                maxLen = max(maxLen, leftIncrement * 2);
            else if (leftIncrement < rightIncrement) 
                leftIncrement = rightIncrement = 0;            
        }
        leftIncrement = rightIncrement = 0;
        for (int i  = (int)s.size() - 1; i >= 0; i --) {
            s[i] == ')' ? rightIncrement++ : leftIncrement++;
            if (rightIncrement == leftIncrement)
                maxLen = max(maxLen, rightIncrement * 2);
            else if (leftIncrement > rightIncrement)
                 leftIncrement = rightIncrement = 0;
        }
        return maxLen;
    }
};
