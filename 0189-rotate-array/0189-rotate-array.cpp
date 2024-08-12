class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        
        int n = nums.size();
        k = k % n; // Handle cases where k is greater than n

    if (k == 0) return;
        //reversing the whole array
        reverse(nums.begin(),nums.end());
        //reversing 1st part
        reverse(nums.begin(), nums.begin()+k);
        //reversing the end part
        reverse(nums.begin()+k, nums.end());

        for(int num: nums)
        {
            cout<<num<<" ";
        }
    }
};