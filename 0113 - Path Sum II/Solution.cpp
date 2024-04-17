class Solution {
public:
    void solve(TreeNode* root, int targetSum, int sum ,vector<vector<int>> &ans,vector<int>temp)
    {
        //base case
        if(root==NULL)return;

        //1) ek case solve karna hai
        sum += root->val;
        // add in temp vector
        temp.push_back(root->val);
        // standing on leaf node
        if(root->left == NULL && root->right == NULL){
            // verify
        if(sum==targetSum) // so if the sum of the path is equal to target 
        // add that temp vector to ans vector (2D vec)
        {
            ans.push_back(temp);
        }
        else{
            return;
        }
        }
        //now rest of the cases recursion will handle
        solve(root->left, targetSum, sum ,ans,temp);
        solve(root->right,targetSum, sum ,ans,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum = 0;
        solve(root,targetSum, sum ,ans,temp);
        return ans;
    }
};
