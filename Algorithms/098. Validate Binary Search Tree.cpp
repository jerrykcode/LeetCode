/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) {
        	max = min = root->val;
        	return true;
        }
        if (root->left != NULL) {
        	if (!isValidBST(root->left)) return false;
        	leftMax = max;
        	leftMin = min;
        	if (root->val <= leftMax) return false;
        }
        if (root->right != NULL) {
        	if (!isValidBST(root->right)) return false;
        	rightMax = max;
        	rightMin = min;
        	if (root->val >= rightMin) return false;
        }
        max = root->right == NULL ? root->val : rightMax;
        min = root->left == NULL ? root->val : leftMin;
        return true;
    }
private:
	int max, min, leftMax, leftMin, rightMax, rightMin;
};
