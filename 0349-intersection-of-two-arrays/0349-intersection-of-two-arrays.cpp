class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s(nums1.begin(), nums1.end());
        set<int> res;

        for(int num : nums2)
        {
            if (s.find(num) != s.end()) { 
                res.insert(num);  
            }
        }
        vector<int> result(res.begin(), res.end());
        return result;

    }
};