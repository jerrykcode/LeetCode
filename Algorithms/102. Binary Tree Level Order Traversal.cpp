/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
typedef TreeNode * Tree;
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == NULL) return result;
		vector<int> level;
		level.push_back(root->val);
		result.push_back(level); //0th level
		level.clear(); //move into next level
		queue<Tree> q;
		q.push(root);
		Tree last = root, tail = root; //last is the last node push into the queue; tail is the last node in the previous level
		while (!q.empty()) {
			Tree t = q.front();
			q.pop();
			if (t->left != NULL) {
				q.push(t->left);
				level.push_back(t->left->val);
				last = t->left;
			}
			if (t->right != NULL) {
				q.push(t->right);
				level.push_back(t->right->val);
				last = t->right;
			}
			if (t == tail && !level.empty()) { //Move into next level
				result.push_back(level);
				level.clear();
				tail = last;
			}
		}
		return result;
	}
};