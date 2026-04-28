/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int solve(TreeNode* root, TreeNode* p, TreeNode* q , TreeNode* &ans)
    {
        if(root == NULL) return 0;
        //start recursion
        int left = solve(root->left, p , q, ans);
        int right = solve(root->right, p, q, ans);
        int self = 0;
        if(root == p || root == q)
        {
            self = 1;
        }
        int total = left + self + right;
        if(total == 2 && ans == NULL)
        {
            ans = root;
        }

        return total;
    }
    //-------X-------X----------------X--------------X----------------X-----------------X-

    //DIFF METHOD
    TreeNode* func(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;

        TreeNode* left = func(root->left, p, q);
        TreeNode* right = func(root->right, p, q);

        if(left && right) return root;
        return left ? left : right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        // TreeNode* ans = NULL;
        // solve(root, p,q,ans);
        // return ans;

        TreeNode* ans = func(root, p ,q);
        return ans;
    }
};