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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        stack<vector<int>> s;
        vector<int> level;
        level.push_back(root->val);
        s.push(level); //0th level
        level.clear();
        queue<Tree> q;
        q.push(root);
        Tree last = root; //The last node push into the queue
        Tree tail = root; //The last node of the previous level
        while (!q.empty()) {
            Tree t = q.front();
            q.pop();
            if (t->left != NULL) {
                level.push_back(t->left->val);
                q.push(t->left);
                last = t->left;
            }
            if (t->right != NULL) {
                level.push_back(t->right->val);
                q.push(t->right);
                last = t->right;
            }
            if (t == tail && !level.empty()) {
                s.push(level);
                level.clear();
                tail = last;
            }
        }
        while (!s.empty()) {
            level = s.top();
            s.pop();
            result.push_back(level);
        }
        return result;
    }
};