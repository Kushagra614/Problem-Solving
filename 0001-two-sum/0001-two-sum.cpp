class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // ---------------BRUTE FORCE----------------------------------
        // vector<int>ans;

        // for(int i = 0; i< nums.size(); i++)
        // {
        //     for(int j = i+1; j < nums.size(); j++)
        //     {
        //         if(nums[i] + nums[j] == target)
        //         {
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;

        // -------------OPTIMISED-----------------------------------------
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++)
        {
            int rest = target - nums[i];
        

        if(mp.find(rest) != mp.end())
        {
            return{mp[rest], i};
        }

        mp[nums[i]] = i;
        }

        return{};
    }
};