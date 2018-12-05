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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return createTree(inorder, postorder, 0, n - 1, 0, n - 1);
    }
private:
    Tree createTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd);
};

Tree Solution::createTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd) return NULL;   
    int root = postorder[postEnd];
    Tree t = new TreeNode(root);
    int inorderIndex = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root) {
            inorderIndex = i;
            break;
        }
    }
    int leftSize = inorderIndex - inStart;
    t->left = createTree(inorder, postorder, inStart, inorderIndex - 1, postStart, postStart + leftSize - 1);
    t->right = createTree(inorder, postorder, inorderIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
    return t;
}