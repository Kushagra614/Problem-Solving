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
    int kthSmallest(TreeNode* root, int &k) {
        // base case
        if(root==NULL)
        {
            return -1;

        }

        //LNR
        //L
        int leftAns = kthSmallest( root->left,  k);
        if(leftAns!=-1)
        return leftAns;

        //n
        k--;
        if(k==0)
        {
            return root->val;
        }

        //R
         int rightAns = kthSmallest( root->right,  k);
         return rightAns;
    }
    
};