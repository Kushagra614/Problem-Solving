class Solution {
public:
    int balance(TreeNode* root) {
        if(root == NULL) {
            return 1;
        }

        int leftlen = balance(root->left);
        if (leftlen == -1) return -1; 

        int rightlen = balance(root->right);
        if (rightlen == -1) return -1; 

        if(abs(leftlen - rightlen) > 1 ) {
            return -1;
        } else {
            return max(leftlen, rightlen) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return balance(root) != -1;
    }
};