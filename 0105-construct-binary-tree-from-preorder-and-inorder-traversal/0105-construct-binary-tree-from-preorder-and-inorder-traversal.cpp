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
    TreeNode* solve(vector<int>&preorder, vector<int>&inorder, int &preIdx, int startIdx, int endIdx,unordered_map<int,int>&mp)
    {
        //base case
        if(preIdx >= preorder.size() || startIdx > endIdx) return NULL;

        //root creation
        int ele = preorder[preIdx];
        TreeNode* root = new TreeNode(ele);
        preIdx++;

        //find the pos of this node in inorder
        int pos = mp[ele];

        //recursivly solve
        root->left = solve(preorder, inorder, preIdx, startIdx, pos-1, mp);
        root->right = solve(preorder, inorder, preIdx, pos+1, endIdx, mp);

        //return the ans
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //idx of preorder
        int preorderIdx = 0;
        //mp storing
        unordered_map<int,int>mp;
        //push all the inorder ele in mp
        for(int i = 0; i < inorder.size() ; i++)
        {
            mp[inorder[i]] = i;
        }
        TreeNode* ans = solve(preorder, inorder, preorderIdx, 0, inorder.size()-1, mp);
        return ans;

    }
};