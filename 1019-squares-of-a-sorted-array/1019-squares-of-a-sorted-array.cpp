class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        for(int i = 0; i<nums.size(); i++)
        {
            nums[i] = nums[i]*nums[i];
        }

        // //now sorting using two pointers
        // // sort(nums.begin(), nums.end());
        // return nums;

        int i = 0;
        int j = nums.size()-1;
        int pos = nums.size()-1;

        vector<int>ans(nums.size());

        while(i<=j)
        {
            if(nums[i]<nums[j])
            {
                ans[pos] = nums[j];
                j--;
                pos--;
            }
            else
            {
                ans[pos] = nums[i];
                i++;
                pos--;
            }
        }

        return ans;
        


    }
};