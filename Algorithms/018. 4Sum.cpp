struct Tuple {
	Tuple(int a, int b, int index_a, int index_b)
		: a(a), b(b), index_a(index_a), index_b(index_b) {}
	int a, b;
	int index_a, index_b;
};

bool compare(Tuple t0, Tuple t1) {
	return (t0.a + t0.b) < (t1.a + t1.b);
}

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() == 0) return result;
		vector<Tuple> tuples;
		for (int i = 0; i < nums.size(); i++)
			for (int j = i + 1; j < nums.size(); j++) {
				tuples.push_back(Tuple(nums[i], nums[j], i, j));
			}
		sort(tuples.begin(), tuples.end(), compare);
		int i = 0, j = tuples.size() - 1;
		while (i < j) {
			int sum = tuples[i].a + tuples[i].b + tuples[j].a + tuples[j].b;
			if (sum == target) {
				int range_i = i;
				while (range_i < j && tuples[range_i].a + tuples[range_i].b == tuples[i].a + tuples[i].b) range_i++;
				int range_j = j;
				while (range_j > i && tuples[range_j].a + tuples[range_j].b == tuples[j].a + tuples[j].b) range_j--;
				for (int tmp_i = i; tmp_i < range_i; tmp_i++)
					for (int tmp_j = j; tmp_j > range_j; tmp_j--) {
						if (tmp_i < tmp_j) {
							addQuadruplets(tuples[tmp_i], tuples[tmp_j]);
						}
					}
				i = range_i;
				j = range_j;
			}
			else if (sum < target) {
				i++;
			}
			else j--;
		}
		return result;
	}
private:

	vector<vector<int>> result;

	void addQuadruplets(Tuple t0, Tuple t1) {
		if (t0.index_a == t1.index_a || t0.index_a == t1.index_b) return;
		if (t0.index_b == t1.index_a || t0.index_b == t1.index_b) return;
		vector<int> quadruplet;
		quadruplet.push_back(t0.a);
		quadruplet.push_back(t0.b);
		quadruplet.push_back(t1.a);
		quadruplet.push_back(t1.b);
		sort(quadruplet.begin(), quadruplet.end());
		for (vector<int> v : result) {
			bool flag = true;
			for (int i = 0; i < 4; i++)
				if (v[i] != quadruplet[i]) {
					flag = false;
					break;
				}
			if (flag) return;
		}
		result.push_back(quadruplet);
	}
};