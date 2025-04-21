class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        // OPTIMIZED
        int minLen = INT_MAX;
        int i = 0;
        int j = 0;
        int sum = 0;

        while(j<nums.size())
        {
            sum += nums[j];
            

            while(sum >= target)
            {
                int len = j-i+1;
                minLen = min(minLen , len);

                sum -= nums[i];
                i++;
            }
            j++;
        }

        if(minLen == INT_MAX) return 0;
        else return minLen;
        

// -------X---------X------------X----------X-----------X------------X--------------X
        // int minLen = INT_MAX;

        // for(int i = 0; i<nums.size(); i++)
        // {
        //     int sum = 0;
        //     for(int j = i; j<nums.size(); j++)
        //     {
        //         sum+= nums[j];
        //         if(sum >= target )
        //         {
        //             minLen = min(minLen, j-i+1);
        //         }

        //     }
        // }
        // if(minLen == INT_MAX) return 0;
        // else return minLen;
    }
};