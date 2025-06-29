class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        set<int> st;
        vector<int> ans;

        for(auto i : nums) st.insert(i);
        for(auto i : st) ans.push_back(i);

        int maxLen = 1;
        int count = 1;

        for (int i = 0; i < ans.size()-1; i++) {

            if (abs(ans[i] - ans[i + 1]) == 1)
            {
                count++;
            }
            else
            {
                count = 1;
            }

            maxLen = max(count, maxLen);
        }
        return maxLen;
    }
};