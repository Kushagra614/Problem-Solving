class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int diff = 0;
        int maxDiff = INT_MAX;
        int sum = 0;

        for(int i = 0; i<nums.size(); i++)
        {
            int j = i+1;
            int k = nums.size()-1;

            while(j<k)
            {
                int add = nums[i] + nums[j] + nums[k];
                diff = abs(add - target);
                {
                    if(diff < maxDiff)
                    {
                        maxDiff = diff;
                        sum = nums[i] + nums[j] + nums[k];
                        
                    }
                    
                    if(nums[i] + nums[j] + nums[k] < target)
                    {
                        j++;
                    }
                    else
                    {
                        k--;
                    }
                }
                
                
            }

        }
        return sum;
    }
};