class Solution {
public:
    int findHeight(TreeNode* root)
    {
        //base case
        if(root==NULL)return 0;
        if(root->left == NULL && root-> right == NULL)return 1;
        
        int leftH = findHeight(root->left);
        int rightH = findHeight(root->right);
        int finalans = max(leftH, rightH)+1;
        return finalans;
        
        
    }
    bool isBalanced(TreeNode* root) {
        
        //base case
        if(root==NULL)return 1;
        if(root->left == NULL && root->right == NULL) return 1;

        //current node
        int leftH = findHeight(root->left);
        int rightH = findHeight(root->right);
        int diff = abs(leftH-rightH);
        bool ans = (diff<=1);

        //we are checking if the at everynode the leftsubtree and right subtree are balanced or not
        bool leftans = isBalanced(root->left);
        bool rightans = isBalanced(root->right);

        // now if the abs diff is <=1 and left and right subtrees are also balanced then the whole tree will be balanced
        if(ans && leftans && rightans)return true;
        else return false;

    }
};
