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

    bool dfs(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL) return true;
        else if(p == NULL && q != NULL || p != NULL && q == NULL) return false;
        else
        {
            if(p->val != q->val)return false;
            else
            {
                return (dfs(p->left, q->left) && dfs(p->right, q->right));
            }

        }
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // we wil perform pre order traversal and check if the nodes are same or not
        bool ans = dfs(p,q);
        if(ans == true) return true;
        else return false;
    }
};