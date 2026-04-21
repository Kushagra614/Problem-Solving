/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        else if (p == NULL && q != NULL || p != NULL && q == NULL) return false;
        else {
            if (p->val != q->val) return false;
            else {
                return (dfs(p->left, q->left) && dfs(p->right, q->right));
            }
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // start traversing the root bt
        if (subRoot == NULL)
            return true;
        if (root == NULL)
            return false;
        //  as soon as i get that root == subroot
        if (root->val == subRoot->val) {
            if (dfs(root, subRoot)) return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};