/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef struct TreeNode *Tree;
typedef Tree BST;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root, p, q);
    }
private:
    BST findLCA(BST bst, BST p, BST q);
};

BST Solution::findLCA(BST bst, BST p, BST q) {
    if (bst == NULL) return NULL;
    if ((bst->val > p->val && bst->val < q->val) || (bst->val < p->val && bst->val > q->val)) return bst;
    else if (bst == p || bst == q) return bst;
    else if (bst->val > p->val && bst->val > q->val) return findLCA(bst->left, p, q);
    else return findLCA(bst->right, p, q);  /* (bst->val < p->val && bst->val < q->val)*/
}