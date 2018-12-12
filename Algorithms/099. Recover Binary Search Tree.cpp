/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//A way which do not need to figure out the two swapped elements to solve this problem 
//is to construct the BST again, with the original structure unchanged. As the inorder 
//traversal of a BST is a sorted array, we can first get the inorder traversal of this 
//tree, sort the result and reconstruct the BST.

typedef TreeNode *Tree;
class Solution {
public:
    void recoverTree(TreeNode* root) {
        dfs(root);
        sort(inorderValue.begin(), inorderValue.end());
        for (int i = 0; i < inorderTree.size(); i++)
            inorderTree[i]->val = inorderValue[i];
        vector<Tree>().swap(inorderTree);
        vector<int>().swap(inorderValue);
    }
private:
    vector<Tree> inorderTree;
    vector<int> inorderValue;
    void dfs(Tree t);
};

void Solution::dfs(Tree t) {
    if (t == NULL) return;
    dfs(t->left);
    inorderTree.push_back(t);
    inorderValue.push_back(t->val);
    dfs(t->right);
}