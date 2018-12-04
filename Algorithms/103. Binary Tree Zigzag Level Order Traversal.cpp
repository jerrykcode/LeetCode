//103. Binary Tree Zigzag Level Order Traversal
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == NULL) return result;
		vector<int> level;
		level.push_back(root->val);
		result.push_back(level);
		level.clear();
		int l = 0;
		queue<Tree> q;
		q.push(root);
		Tree last = root; //The last node push into the queue
		Tree tail = root; //The last node of the previous level
		while (!q.empty()) {
			Tree t = q.front();
			q.pop();
			if (t->left != NULL) {
				level.push_back(t->left->val);
				q.push(t->left);
				last = t->left;
			}
			if (t->right != NULL) {
				level.push_back(t->right->val);
				q.push(t->right);
				last = t->right;
			}
			if (t == tail && !level.empty()) {
				l++;
				if (l % 2) reverse(level);
				result.push_back(level);
				level.clear();
				tail = last;
			}
		}
		return result;
	}
private:
	void reverse(vector<int>& list) {
		for (int i = 0; i < list.size() / 2; i++) {
			int tmp = list[i];
			list[i] = list[list.size() - i - 1];
			list[list.size() - i - 1] = tmp;
		}
	}
};