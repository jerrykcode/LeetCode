/*#include <iostream>
using namespace std;
#include <string>
*/
#ifndef MAX_INT
#define MAX_INT 2147483647
#endif

#ifndef MIN_INT
#define MIN_INT -2147483648
#endif

class Solution {
public:
    int myAtoi(string str) {
        while (str[0] == ' ') str.erase(str.begin()); //Remove white spaces
        if (str[0] != '+' && str[0] != '-' && !isdigit(str[0])) return 0; //First non-white space character is not a valid 
                                                                            //integral number and not '-' or '+' as well
        int sign = str[0] == '-' ? -1 : 1; //Sign
        if (str[0] == '-' || str[0] == '+') str.erase(str.begin()); //Remove the sign
        string digit = ""; //The numerical digits
        while (isdigit(str[0])) {
            digit += str[0];
            str.erase(str.begin());
        }
        if (digit == "") return 0;
        int result = 0;
        for (int i = 0; i < digit.length(); i ++) {
            result += (digit[digit.length() - i - 1] - '0') * pow(10, i);
            if (result < 0) { //Overflow
                return sign == 1 ? MAX_INT : MIN_INT;
            }
        }
        return sign * result;
    }
};

//Test function
/*int main()
{
	string str;
	cin >> str;
	Solution * s = new Solution;
	cout << s ->myAtoi(str);
	return 0;
}*/
