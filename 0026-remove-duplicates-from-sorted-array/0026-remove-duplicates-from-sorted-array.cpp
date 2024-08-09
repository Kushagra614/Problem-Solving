class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // the logic=> we will put all the elemets in a set 
        // which cant have duplicates

        set<int>s;
        int i = 0;
        for(int num:nums)
        {
            s.insert(num);
        }

        nums.clear();
        
        for (int n : s) {
            nums.push_back(n);
        }
        
        return nums.size();
    }
};