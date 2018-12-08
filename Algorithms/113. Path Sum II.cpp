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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) return result;
        vector<int> path;
        path.push_back(root->val);
        dfs(root, root->val, path, sum);
        return result;
    }
private:
    vector<vector<int>> result;
    void dfs(Tree t, int pathSum, vector<int>& path, int target);
};

void Solution::dfs(Tree t, int pathSum, vector<int>& path, int target) {
    if (t->left == NULL && t->right == NULL) {
        if (pathSum == target)
            result.push_back(path);
    }
    if (t->left != NULL) {
        path.push_back(t->left->val);
        dfs(t->left, pathSum + t->left->val, path, target);
        path.pop_back();
    }
    if (t->right != NULL) {
        path.push_back(t->right->val);
        dfs(t->right, pathSum + t->right->val, path, target);
        path.pop_back();
    }
}