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

    vector<int> inorder(TreeNode* root, vector<int>&v)
    {
        //base case
        
            if(root==NULL)
            {
                return v;
            }
        

        //lnr
        //l
        inorder(root->left, v);

        //n
        v.push_back(root->val);

        //r
        inorder(root->right, v);

        return v;
    }

    TreeNode* treeBuilder(vector<int>&v, int s, int e)
    {
        if(s>e)
        {
            return nullptr;
        }

        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(v[mid]);
        // left
        root->left = treeBuilder(v,  s, mid-1);
        // right
        root->right = treeBuilder(v, mid+1, e);

        return root;
        
    }


    TreeNode* balanceBST(TreeNode* root) {

        //base case
        if(root==NULL)
        {
            return NULL;
        }

        vector<int>values;
        inorder(root,values);



        return treeBuilder(values, 0, values.size()-1);
    }
};