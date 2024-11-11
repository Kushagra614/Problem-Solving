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

    void getMinimumDifferenceHelper(TreeNode* root, TreeNode*& prevVal, int& mini)
    {
        //base case
        if(root==NULL)
        {
            return ;
        }

        

        //LNR
        //L
        getMinimumDifferenceHelper (root->left, prevVal, mini);

        //N
        // abs diff between the the root and its left node
        if(prevVal!=NULL){
        int diff = abs(prevVal->val - root->val);
        //get min
        mini = min(mini, diff);
        }
        
        // update the prev val
        prevVal = root;

        //R
        getMinimumDifferenceHelper (root->right, prevVal, mini);

        
    }
    int getMinimumDifference(TreeNode* root) {
        
        //base case
        if(root==NULL)
        {
            return INT_MAX;
        }

        int mini = INT_MAX;
        TreeNode* prevVal = nullptr;
        getMinimumDifferenceHelper(root, prevVal, mini);
        return mini;
        
    }
};