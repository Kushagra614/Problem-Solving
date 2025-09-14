class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1;
        int suff = 1;
        int maxPro = INT_MIN;

        for(int i = 0; i < nums.size(); i++)
        {
                pre *= nums[i];
                if(pre > maxPro)
                {
                    maxPro = pre;
                }
                
                if(pre == 0) pre = 1;
            
            
        }

        for(int j = nums.size()-1; j >0; j--)
        {
                suff*= nums[j];
                if(suff > maxPro)
                {
                    maxPro = suff;
                }
            if(suff == 0) suff = 1;
            
        }

        return maxPro;
        
    }
};