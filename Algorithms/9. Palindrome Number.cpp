class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        stack<int> s;
        int tmp;
        for (tmp = x; tmp != 0; tmp /= 10) //x的每一位，从后往前
            s.push(tmp%10); 
        for (tmp = x; tmp != 0 && s.top() == tmp%10; tmp /= 10) s.pop(); //出栈的是从前往后的每一位，判断是否与从后往前相应位相同
        return tmp == 0;
    }
};
