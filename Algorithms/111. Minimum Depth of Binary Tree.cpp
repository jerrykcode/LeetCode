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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        int leftSize = root->left != NULL ? minDepth(root->left) : 0;
        int rightSize = root->right != NULL ? minDepth(root->right) : 0;
        if (leftSize != 0 && rightSize != 0) return min(leftSize, rightSize) + 1;
        else return max(leftSize, rightSize) + 1;
    }
};