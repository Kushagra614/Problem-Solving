class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 0) return 0;
        set<int> st(nums.begin(), nums.end());
        vector<int> ans;
        for (auto i : st) {
            ans.push_back(i);
        }

        int maxLen = 1;
        int count = 1;

        for (int i = 0; i < ans.size()-1; i++) {

            if (abs(ans[i] - ans[i + 1]) == 1) {
                count++;
                maxLen = max(count, maxLen);
            }
            else
            {
                count = 1;
            }
        }
        return maxLen;
    }
};