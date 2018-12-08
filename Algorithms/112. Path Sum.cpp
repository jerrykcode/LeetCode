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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return dfs(root, root->val, sum);
    }
private:
    bool dfs(Tree t, int pathSum, int target);
};

bool Solution::dfs(Tree t, int pathSum, int target) {
    if (t->left == NULL && t->right == NULL) 
        return pathSum == target;
    if (t->left != NULL)
        if (dfs(t->left, pathSum + t->left->val, target)) return true;
    if (t->right != NULL)
        if (dfs(t->right, pathSum + t->right->val, target)) return true;
    return false;
}