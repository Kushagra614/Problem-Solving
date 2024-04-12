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
        
    }
};
