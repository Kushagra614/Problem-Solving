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

    void printRightV(TreeNode* root , int lvl, vector<int>&v)
    {
        if(root==NULL)
        {
            return;
        }

        if(lvl==v.size())
        {
            v.push_back(root->val);
        }
        printRightV(root->right, lvl+1, v);
        printRightV(root->left, lvl+1, v);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        printRightV(root, 0, v);
        return v;
    }
};