class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int i = 0;
        int j = nums.size()-1;
        while(i<=j)
        {
            if(nums[i] == val){
                if(nums[j] != val)
                {
                    nums[i] = nums[j];
                    i++;
                    
                }
                j--;
            }
            else
            {
                i++;
            }
        }
        return i;
        // int j = 0;
        // for(int i = 0; i<nums.size(); i++)
        // {
        //     if(nums[i]!= val)
        //     {
        //         nums[j] = nums[i];
        //         j++;
        //     }
        // }
        // return j;
    }
};