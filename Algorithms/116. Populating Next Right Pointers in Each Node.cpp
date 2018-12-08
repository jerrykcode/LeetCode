/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
typedef struct TreeLinkNode *Tree;
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        Tree last = root;
        Tree tail = root;
        queue<Tree> q;
        q.push(root);
        bool flag = true;
        while (!q.empty()) {
            Tree t = q.front();
            q.pop();
            if (t->left != NULL) {
                q.push(t->left);
                if (flag) flag = false;
                else last->next = t->left;
                last = t->left;
            }
            if (t->right != NULL) {
                q.push(t->right);
                if (flag) flag = false;
                else last->next = t->right;
                last = t->right;
            }
            if (t == tail) {
                flag = true;
                tail = last;
            }
        }
    }
};