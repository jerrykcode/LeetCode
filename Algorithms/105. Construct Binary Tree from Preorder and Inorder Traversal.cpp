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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return createTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}
private:
	Tree createTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd);
};

Tree Solution::createTree(vector<int>& preorder, vector<int>& inorder, int preStart, int  preEnd, int inStart, int inEnd) {
	if (preEnd - preStart < 0) return NULL;
	int root = preorder[preStart];
	Tree T = new TreeNode(root);
	int rootInorderIndex = 0;
	for (int i = inStart; i <= inEnd; i++)
		if (inorder[i] == root) {
			rootInorderIndex = i;
			break;
		}
	int leftSize = rootInorderIndex - inStart;
	T->left = createTree(preorder, inorder, preStart + 1, preStart + leftSize, inStart, rootInorderIndex - 1);
	T->right = createTree(preorder, inorder, preStart + leftSize + 1, preEnd, rootInorderIndex + 1, inEnd);
	return T;
}