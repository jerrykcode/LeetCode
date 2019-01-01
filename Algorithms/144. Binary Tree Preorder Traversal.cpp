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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if (root == NULL) return preorder;
        Tree t = root;
        stack<Tree> s;
        while (1) {
            preorder.push_back(t->val);
            s.push(t);
            while (t->left != NULL) {
                t = t->left;
                preorder.push_back(t->val);
                s.push(t);
            }
            Tree tmp = t;
            while (t->right == NULL || t->right == tmp) {               
                tmp = t;
                s.pop();
				if (s.empty()) goto END;
                t = s.top();      
            }
            t = t->right;
        }
    END:
        return preorder;
    }
};
