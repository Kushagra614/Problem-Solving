class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        //making queue for storage
        queue<TreeNode*>q;
        int count = 0;
        q.push(root);
        q.push(NULL);
        
        
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();

            if(front==nullptr)
            {
                count++;
            if (!q.empty()) 
            {
                q.push(nullptr);
            }
            }
            else{
                if (front->left != nullptr)
            {
                q.push(front->left); 
            }
            if (front->right != nullptr)
            {
                q.push(front->right); 
            }
            }
        }
        return count;
        

    //SOLVING BY RECUSRION
    int maxDepth(TreeNode* root) {
        //base case
        if(root == nullptr) {
            return 0;
        }
        int leftheight = maxDepth(root->left);
        int rightheight = maxDepth(root->right);
        int height = max(leftheight, rightheight)+1;
        return height;
    }
    }
};
