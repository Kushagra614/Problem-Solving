class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1;

        int pSum = 0;
        int count = 0;

        for(auto i : nums)
        {
            pSum += i;
            int rem = pSum - k;
            if(mp.count(rem))
            {
                count += mp[rem];

            }

            mp[pSum]++;
        }
        return count;

    }
};