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

    //BRUTE FORCE APPROCH

    // TreeNode* solve(TreeNode* root, int val)
    // {
    //     if(root==nullptr)
    //     {
    //        return new TreeNode(val); 
    //     }

    //     if(root->val > val)
    //     {
    //         root->left = solve(root->left, val);
    //     }
        
    //     if(root->val < val)
    //     {
    //         root->right = solve(root->right, val);
    //     }

    //     return root;


    // }
    // TreeNode* bstFromPreorder(vector<int>& preorder) {
        
    //     TreeNode* root = nullptr;
    //     for( int val : preorder)
    //     {
    //         root = solve(root, val);
    //     }
    //     return root;
    // }


    // OPTIMAL APPROACH

    TreeNode* solve(TreeNode* root, int &min, int &max,int val)
    {
        //base case
        if(root==NULL)
        {
            return new TreeNode(val);
        }

        //NLR
        //N

        if(val > min && val < max)
        {
             if (val < root->val) {
            root->left = solve(root->left, min, root->val, val);  // Go left
        }
        else {
            root->right = solve(root->right, root->val, max, val);  // Go right
        }
        }
        

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* root = nullptr;
        int min = INT_MIN;
        int max = INT_MAX;

        for(int val : preorder)
        {
            root = solve(root, min , max , val);
        }

        return root;
        
    }
    
};