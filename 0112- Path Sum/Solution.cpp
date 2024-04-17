class Solution {
public:

    bool solve(TreeNode* root, int targetSum, int sum)
    {
    //base case 
    if(root==nullptr)return false;
    sum+=root->val;
    if(root->left == nullptr && root->right==NULL)
    {  
        //verify
        if(sum==targetSum)
        {
            return true;
        }
        else{
            false;
        }

    }
    bool leftAns = solve(root->left,targetSum,  sum);
    bool rightAns = solve(root->right ,targetSum, sum);
    //if anyone one of them is true we will return true
    return leftAns || rightAns;
}

    bool hasPathSum(TreeNode* root, int targetSum) {
    int sum = 0;
    bool ans = solve(root, targetSum, sum);
    return ans;

    }
};
