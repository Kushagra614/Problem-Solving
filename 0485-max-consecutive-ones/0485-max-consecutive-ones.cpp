class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        vector<int>v;
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                count++;
                v.push_back(count);


            }
            if(nums[i]!=1)
            {
                count = 0;
            }
        }
        auto maxIt = max_element(v.begin(), v.end());

        if (maxIt != v.end()) {
        // Store the maximum element in a variable
        int ans = *maxIt;
        return ans;
        
    }
    return 0;
    }
    
};