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

    bool solve(TreeNode* root, long long int lb,long long int ub)
    {
        //base cse
        if(root==NULL)
        {
            return true;
        }

        bool cond1 = (root->val > lb);
        bool cond2 = (root->val < ub);
        bool leftans = solve(root->left,lb,root->val);
        bool rightans = solve(root->right,root->val,ub);

        if(cond1 && cond2 && leftans && rightans)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {

        //ranges
        long long int lb =  -2147483947;
        long long int ub = 2147483947;

        bool ans = solve(root, lb , ub);
        return ans;        
    }
};