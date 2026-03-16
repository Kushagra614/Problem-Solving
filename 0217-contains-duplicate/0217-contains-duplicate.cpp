class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st(nums.begin(), nums.end());
        if(n != st.size()) return true;
        else return false;
    }
};