/*
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits != "") {
            init_map();
            dfs(0, digits);
        }
        return combinations;
    }
private:
    map<int, vector<char>> digit_to_letter;
    string result;
    vector<string> combinations;    

    void init_map() {
		digit_to_letter[0].push_back('_');
        char c = 'a';
        for (int i = 2; i <= 9; i ++) {
            for (int j = 0; j < 3; j ++)
                digit_to_letter[i].push_back(c++);
            if (i == 7 || i == 9) digit_to_letter[i].push_back(c++);
        }
    }
    
    void dfs(int index, string digits) {
        if (index >= digits.length()) {
            combinations.push_back(result);
            return;   
        }
		int d = (int)digits[index] - (int)'0';
        for (int i = 0; i < digit_to_letter[d].size(); i ++) {
            result += digit_to_letter[d][i];
            dfs(index + 1, digits);
			result.erase(result.end() - 1);
        }
    }
};

//Test
/*
int main()
{
	Solution *s = new Solution;
	string digits;
	cin >> digits;
	vector<string> combinations = s->letterCombinations(digits);
	for (int i = 0; i < combinations.size(); i ++)
		cout << combinations[i] << endl;
	return 0;
}
*/
