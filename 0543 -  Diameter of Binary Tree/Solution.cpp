class Solution {
public:

    int findHeight(TreeNode* root)
    {
        //base case
        if(root==NULL)return 0;
        if(root->left == NULL && root->right== NULL)return 1;
         int leftH = findHeight(root->left)+1;
         int rightH = findHeight(root->right)+1;
         int height = max(leftH, rightH);
         return height;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //base case
        if(root==NULL)return 0;

        if(root->left == NULL && root->right== NULL)return 0; // this will be 0 as we have to count the no. of edges and not the number of nodes for diameter

        //height of left subtree(if both the nodes are in left)
        int option1 = diameterOfBinaryTree(root->left);
        //height of right subtree(if both the nodes are in right)
        int option2 = diameterOfBinaryTree(root->right);
        //if nodes are in both left and right
        int option3 = findHeight(root->left)+ findHeight(root->right);
        int diameter = max(option1 , max(option2,option3));
        return diameter;
    }
};
