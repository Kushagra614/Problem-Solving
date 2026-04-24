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

    void inorder(TreeNode* root, vector<int>& ans)
    {
         //inorder traversal of a BST-> gives the elements in inc sorted order 
        if(root == NULL) return;
        //inorder -> LNR
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);

    }
    bool isValidBST(TreeNode* root) {
        // if(root == NULL) return true;

        // //checking
        // if(root->left != NULL )
        // {
        //     if(root->left->val >= root->val) return false;
        // }
        // if(root->right != NULL)
        // {
        //     if(root->right->val <= root->val) return false;
        // }

        // return (isValidBST(root->left) && isValidBST(root->right));
//-----X---------X----------X--------X--------X-------------X-------------X-------------X

        vector<int>ans;
        inorder(root, ans);
        int check = ans[0];
        bool res = true;
        for(int i = 1; i< ans.size(); i++)
        {
            if(check >= ans[i])
            {
                res = false;
            }
            check = ans[i];
        }

        return res;

    }
};