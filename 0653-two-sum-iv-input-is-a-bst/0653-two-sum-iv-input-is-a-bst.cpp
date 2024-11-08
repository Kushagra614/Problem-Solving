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

    vector<int> inorder (TreeNode* root, vector<int>&v)
    {
        //base case
        if(root==NULL)
        {
            return v;

        }

        //LNR
        //L
        inorder(root->left,v);
    

        //N
        v.push_back(root->val);

        //R
        inorder(root->right,v);
        
        return v;


    }

    bool solve(TreeNode* root,int k, vector<int>&res)
    {
        res = inorder(root, res);
        int s = 0;
        int e = res.size()-1;
        bool ans = false;
        while(s<e)
        {
            if(res[s]+res[e] == k)
            {
                ans = true;
                break;
            }
            else if(res[s]+res[e]>k){
                e--;
            }
            else 
            {
                s++;
            }
            
        }
        return ans;


    }
    bool findTarget(TreeNode* root, int k) {
    
        vector<int>res;
        bool cook = solve(root, k, res);
        return cook;
    }
};