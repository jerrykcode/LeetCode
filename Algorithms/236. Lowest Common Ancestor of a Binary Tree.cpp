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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<Tree> p_path;
        vector<Tree> q_path;
        p_path.push_back(root);      
        dfs(root, p, p_path);
        q_path.push_back(root);
        dfs(root, q, q_path);
        Tree result = NULL;        
        for (auto p_it = p_path.begin(), q_it = q_path.begin(); p_it != p_path.end() && q_it != q_path.end(); p_it++, q_it++)
            if (*p_it != *q_it) {
                result = *(p_it - 1);
                break;   
            }
        if (result == NULL) {
            result = p_path.size() < q_path.size() ? *(p_path.end() - 1) : *(q_path.end() - 1);
        }    
        p_path.clear();
        vector<Tree>().swap(p_path);
        q_path.clear();
        vector<Tree>().swap(q_path);
        return result;
    }
private:
    bool dfs(Tree root, Tree p, vector<Tree>& path);
};

bool Solution::dfs(Tree root, Tree p, vector<Tree>& path) {
    if (root == p) {
        return true;
    }
    if (root->left != NULL) {
        path.push_back(root->left);
        if (dfs(root->left, p, path)) return true;
        path.pop_back();
    }
    if (root->right != NULL) {
        path.push_back(root->right);
        if (dfs(root->right, p, path)) return true;
        path.pop_back();
    }
    return false;
}