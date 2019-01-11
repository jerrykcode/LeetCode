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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) : _iterator(0) {
        dfs(root);
        _size = _inorder.size();
    }
    
    ~BSTIterator() {
        _inorder.clear();
        vector<int>().swap(_inorder);
    }
    
    /** @return the next smallest number */
    int next() {
        return _inorder[_iterator++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return _iterator < _size;
    }
private:
    
    void dfs(Tree t);
    
    vector<int> _inorder;
    int _iterator;
    int _size;
};

void BSTIterator::dfs(Tree t) {
    if (t == NULL) return;
    if (t->left != NULL) dfs(t->left);
    _inorder.push_back(t->val);
    if (t->right != NULL) dfs(t->right);
}


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */