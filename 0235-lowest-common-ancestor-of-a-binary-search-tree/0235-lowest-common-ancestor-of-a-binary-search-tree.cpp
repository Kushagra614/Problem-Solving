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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL)
        {
            return NULL;
        }

        //4 cases
        //case1: root is LCA
        else if(root->val > p->val && root->val < q->val || root->val > q->val && root->val < p->val || root->val == p->val || root->val == q->val)
        {
            return root;
        }

        // //case2: root is LCA
        // else if(root->val > q->val && root->val < p->val)
        // {
        //     return root;
        // }

        //case3: LCA is leftsubTree
        else if(root->val > p->val && root->val > q->val)
        {
            TreeNode* leftAns =  lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }

        //case4: LCA is rightsubTree
        else if(root->val < p->val && root->val < q->val)
        {
            TreeNode* rightAns =  lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }
        
        else{
            return NULL;
        }
    }
};