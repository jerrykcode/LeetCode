class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") return "0";
		string result = "";
		for (int i = 0; i <= 9; i++) multiplyOneResult[i] = ""; //cache
		for (int i = num2.size() - 1; i >= 0; i--) {
			string str = multiplyOne(num1, (int)num2[i] - (int)'0');
			if (result == "") {
				result = str;
			}
			else {
				for (int j = 0; j < num2.size() - i - 1; j++) str += "0";
				result = add(result, str);
			}
		}
		return result;
	}
private:
	string add(string str0, string str1); //add two strings
	string multiplyOne(string str, int digit); //mutiply string by an one-digit number
	string multiplyOneResult[10]; //cache
};

string Solution::add(string str0, string str1) {
	string result = "";
	//Only one while loop will be excuted.
	while (str0.size() < str1.size()) str0 = "0" + str0;
	while (str1.size() < str0.size()) str1 = "0" + str1;
	int k = 0;
	for (int i = str0.size() - 1; i >= 0; i--) {
		int sum = (int)str0[i] - (int)'0' + (int)str1[i] - (int)'0' + k;
		k = sum / 10;
		sum %= 10;
		result = to_string(sum) + result;
	}
	if (k != 0)
		result = to_string(k) + result;
	return result;
}

string Solution::multiplyOne(string str, int digit) {
	if (multiplyOneResult[digit] != "") return multiplyOneResult[digit];
	string result = "";
	int k = 0;
	for (int i = str.size() - 1; i >= 0; i--) {
		int sum = ((int)str[i] - (int)'0') * digit + k;
		k = sum / 10;
		sum %= 10;
		result = to_string(sum) + result;
	}
	if (k != 0)
		result = to_string(k) + result;
	multiplyOneResult[digit] = result;
	return result;
}