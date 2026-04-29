/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* l , TreeNode* r)
    {
        //base case
        if(l == NULL && r == NULL) return true;
        else if((l == NULL && r != NULL) || (l != NULL && r == NULL)) return false;
        //check if values are same
        else if(l->val != r->val) return false;
    
        return ((solve(l->left, r->right)) && (solve(l->right, r->left)));
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return false;
        TreeNode* l = root->left;
        TreeNode* r = root->right;

        return solve(l,r);
    }
};