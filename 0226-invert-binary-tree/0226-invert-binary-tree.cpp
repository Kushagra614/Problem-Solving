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
    void swap(TreeNode* &leftNode, TreeNode* &rightNode)
    {
        TreeNode* temp = leftNode;
        leftNode = rightNode;
        rightNode = temp;

    }
    TreeNode* invertTree(TreeNode* root) {
        // we will use a noral swap logic using a temp variable

        if(root == NULL) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;

    }
};