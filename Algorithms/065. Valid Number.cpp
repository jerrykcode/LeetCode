#define NO_INDEX 0xffffffff

#define IS_SPACE(c) (c == ' ')
#define IS_NUMBER(c) (c >= '0' && c <= '9')
#define IS_EXPONENT(c) (c == 'e')
#define IS_SIGN(c) (c == '-' || c== '+')
#define IS_POINT(c) (c == '.')

class Solution {
public:
    bool isNumber(string s) {     
        size_t start, end;
        for (start = 0; start < s.length() && IS_SPACE(s[start]); start++); //ignore the ' ' in the begin
        for (end = s.length() - 1; end >= 0 && IS_SPACE(s[end]); end--); //ignore the ' ' in the end
        bool has_number = false; //No number in the string yet
        size_t point_index = NO_INDEX; //The index of decimal point '.'
        size_t e_index = NO_INDEX; //The index of 'e'
        for (size_t i = start; i <= end; i++) {
            if (IS_NUMBER(s[i])) {
                has_number = true; //There is number in the string              
            }
            else if (IS_EXPONENT(s[i])) {
                if (!has_number) { //If no number appeared before 'e', return false
                    return false;
                }
                if (e_index == NO_INDEX) { //If no 'e' appeared before
                    e_index = i;
                }
                else return false; //'e' appeared more than once, return false
                if (i == end) return false; //'e' is the last one, return false
            }
            else if (IS_SIGN(s[i])) {
                if (i != start && i != e_index + 1) return false; //If the sign is not the first one or the one after 'e', return false
                if (i == end) return false; //If the sign is the last one, return false
            }
            else if (IS_POINT(s[i])) {               
                if (e_index != NO_INDEX) { //If 'e' appeared before '.', return false
                    return false;
                }
                if (point_index == NO_INDEX) { //No '.' appeared before
                    point_index = i;                    
                }
                else return false; //'.' appeared more than once, return false
            }            
            else return false; //other character, return false
        }
        return has_number; //There must be some number in the string
    }
};