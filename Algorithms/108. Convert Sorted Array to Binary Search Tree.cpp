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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(nums, 0, nums.size() - 1);
    }
private:
    Tree createTree(vector<int>& nums, int start, int end);
};

Tree Solution::createTree(vector<int>& nums, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    Tree t = new TreeNode(nums[mid]);
    t->left = createTree(nums, start, mid - 1);
    t->right = createTree(nums, mid + 1, end);
    return t;
}