class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxno = 0;
        int ans = 0;
        for(auto num : nums)
        {
            mp[num]++;

            if(mp[num] > maxno)
            {
                maxno = mp[num];
                ans = num;
            }
        }
        return ans;

    }
};