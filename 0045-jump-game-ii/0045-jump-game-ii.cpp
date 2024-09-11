class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int f = 0;
        int end = 0;
        int count = 0;
        if(n==1)
        {
            return 0;
        }
        for(int i = 0; i<nums.size();i++)
        {
            f = max(f, nums[i]+i);

           
                if(i == end){
                    count++;
                    end = f;
                }
           
            
            
            if(end>=n-1)
            {
                
                break;
            }
        }
        return count;
    }
};