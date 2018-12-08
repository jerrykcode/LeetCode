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
    void flatten(TreeNode* root) {
        inorderTraversal(root);
    }
private:
    Tree list = NULL;
    void inorderTraversal(Tree t);
};

void Solution::inorderTraversal(Tree t) {
    if (t == NULL) return;
    if (list != NULL) list->right = t;
    list = t;
    Tree left = t->left, right = t->right;
    t->left = NULL;
    inorderTraversal(left);
    inorderTraversal(right);
}