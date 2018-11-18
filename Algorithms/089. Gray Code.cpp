class Solution {
public:
	vector<int> grayCode(int n) {
		int size = pow(2, n);
		divide(0, size - 1, true);
		return result;
	}
private:
	vector<int>result;
	void divide(int start, int end, bool flag);
};

void Solution::divide(int start, int end, bool flag) {
	if (start == end) { //Only 1 value in the sequence
		result.push_back(start);
		return;
	}
	int size = end - start + 1;
	if (flag) { //First process left part and then process right part
		divide(start, start + size/2 - 1, true);
		divide(start + size/2, end, false);
	} else { //First right and then left
		divide(start + size/2, end, true); //Notice that flag should be true in here!
		divide(start, start + size/2 - 1, false);
	}
}