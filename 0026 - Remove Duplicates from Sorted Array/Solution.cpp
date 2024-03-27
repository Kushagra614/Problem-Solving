class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    // Removing duplicates using unique
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        // Storing unique elements in a set
        // set<int> s(nums.begin(), nums.end());
        // vector<int> v(s.begin(), s.end());

        // Printing the unique elements
        // for (int x : v) {
        //     cout << x << " ";
        // }
        // cout << endl;

        return nums.size();
    }
    
};
