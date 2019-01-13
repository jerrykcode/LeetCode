///The last nodes of each level is the right side view of the tree.

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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSideNodes;
        if (root == NULL) return rightSideNodes;
        queue<Tree> q;
        q.push(root);
        Tree last = root, tail = root; //last is the last node pushed into the queue, tail is the last node of a level
        while (!q.empty()) {
            Tree t = q.front();
            q.pop();
            if (t->left != NULL) {
                q.push(t->left);
                last = t->left;
            }
            if (t->right != NULL) {
                q.push(t->right);
                last = t->right;
            }
            if (t == tail) {
                rightSideNodes.push_back(tail->val);
                tail = last;
            }
        }
        return rightSideNodes;
    }
};
