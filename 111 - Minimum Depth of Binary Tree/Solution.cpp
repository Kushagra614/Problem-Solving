class Solution {
public:
    int solve(TreeNode* root)
    {
        //base case
        if(root==NULL)return 0;
        if(root->left==NULL&&root->right==NULL)return 1;
        if(root->left==NULL)
        return solve(root->right)+1;
        if(root->right==NULL)
        return solve(root->left)+1;

        int leftH = solve(root->left)+1;
        int rightH = solve(root->right)+1;
        return min(leftH, rightH);


  int minDepth(TreeNode* root) {
        
      return solve(root);
    }
        
    
};
