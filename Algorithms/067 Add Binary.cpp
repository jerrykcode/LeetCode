
#define MAX(a, b) a > b ? a : b

class Solution {
public:
	string addBinary(string a, string b) {
		stack<int> s;
		int size_a = a.size(), size_b = b.size();
		int size = MAX(size_a, size_b);
		if (size == 0) return "";
		int k = 0;
		for (int i = 0; i < size; i++) {
			int na = (size_a - i - 1 >= 0) ? ((int)a[size_a - i - 1] - (int)'0') : 0;
			int nb = (size_b - i - 1 >= 0) ? ((int)b[size_b - i - 1] - (int)'0') : 0;
			int n = na + nb + k;
			k = n / 2;
			n = n % 2;
			s.push(n);
		}
		if (k != 0) s.push(k);
		string result = "";
		while (!s.empty()) {
			result += to_string(s.top());
			s.pop();
		}
		return result;
	}
};
