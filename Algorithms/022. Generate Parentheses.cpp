class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        dfs(s, n, n);
        return result;
    }
private:
    vector<string> result;
    void dfs(string s, int left, int right) { //left 为剩下的"("数，rigth为剩下的")"数
        if (left == 0 && right == 0) { //无左右括号
            result.push_back(s);
            return;   
        }
        if (left == right) //剩下的左括号数等于右括号数，此时只能是左括号
            dfs(s + "(", left - 1, right);
        else if (left < right) { //剩下的左括号数小于右括号数
            if (left != 0) dfs(s + "(", left - 1, right);
            dfs(s + ")", left, right - 1);
        }
    }
};
