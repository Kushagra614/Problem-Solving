class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // unordered_set<int>st;

        // for(int i = 0; i< nums.size(); i++)
        // {
        //     if(st.find(nums[i]) != st.end())
        //     {
        //         return true;
        //     }

        //     st.insert(nums[i]);

        //     if(st.size() > k)
        //     {
        //         st.erase(nums[i-k]);
        //     }
        // }
        // return false;

        /// 2ND APPROACH USING 2 POINTERS
        unordered_set<int>st;
        
        for (int i = 0, j = 0; i < nums.size(); i++)
        {
            if(i - j > k)
            {
                st.erase(nums[j]);
                j++;
            }

            if(st.find(nums[i]) != st.end())
            {
                return true;
            }

            st.insert(nums[i]);

        }
        return false;
    }
};