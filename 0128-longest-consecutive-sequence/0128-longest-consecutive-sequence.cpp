class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    //     if (nums.size() == 0) return 0;

    //     set<int> st;
    //     vector<int> ans;

    //     for(auto i : nums) st.insert(i);
    //     for(auto i : st) ans.push_back(i);

    //     int maxLen = 1;
    //     int count = 1;

    //     for (int i = 0; i < ans.size()-1; i++) {

    //         if (abs(ans[i] - ans[i + 1]) == 1)
    //         {
    //             count++;
    //         }
    //         else
    //         {
    //             count = 1;
    //         }

    //         maxLen = max(count, maxLen);
    //     }
    //     return maxLen;

    // -------x------X------X-----------X-----------X---------X----------X

        if(nums.size() == 0) return 0;
        int maxLen = 1;
        unordered_set<int>st;

        for(auto i: nums)
        {
            st.insert(i);
        }


        for(auto it : st)
        {
            if(st.find(it - 1) == st.end())
            {
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end())
                {
                    x++;
                    cnt++;
                }

                maxLen = max(maxLen, cnt);
            }
        }

        return maxLen;
    }
};