class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int count = 0;
        int Psum = 0;
        mp[0] = 1;

        for(auto i : nums)
        {
            Psum += i;
            int diff = Psum - goal;
            if(mp.count(diff))
            {
                count += mp[diff];
            }

            mp[Psum]++;
        }
        return count;
    }
};