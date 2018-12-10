/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef TreeNode *Tree;
class Solution {
public:
	int sumNumbers(TreeNode* root) {
		if (root == NULL) return 0;
		sum = 0;
		vector<int> path;
		path.push_back(root->val);
		dfs(root, path);
		vector<int>().swap(path);
		return sum;
	}
private:
	int sum;
	void dfs(Tree t, vector<int>& path);
	int toInt(vector<int>& v);
};

void Solution::dfs(Tree t, vector<int>& path) {
	if (t == NULL) return;
	if (t->left == NULL && t->right == NULL) {
		sum += toInt(path);
		return;
	}
	if (t->left != NULL) {
		path.push_back(t->left->val);
		dfs(t->left, path);
		path.pop_back();
	}
	if (t->right != NULL) {
		path.push_back(t->right->val);
		dfs(t->right, path);
		path.pop_back();
	}
}

int Solution::toInt(vector<int>& v) {
	int result = 0;
	for (int i = 0; i < v.size(); i++)
		result += v[i] * pow(10, v.size() - i - 1);
	return result;
}