class Solution {
public:
    int reverse(int x) {
        int result = 0, i = -1, tmp = x;
        for ( ; tmp != 0; tmp /= 10, i++) ; //x的位数
        for ( ; x != 0; x /= 10, i --)
            if ((result += (x%10)*pow(10, i))*(x/abs(x)) < 0) return 0; //若与原数符号相反则溢出
         return result;  
    }
};
