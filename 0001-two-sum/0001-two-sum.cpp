class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;  // Map to store the value and its index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];  // Calculate complement
            
            // If complement exists in the map, we found the pair
            if (hashMap.find(complement) != hashMap.end()) {
                return {hashMap[complement], i};  // Return the indices
            }
            
            // Store the current value and its index in the map
            hashMap[nums[i]] = i;
        }
        
        return {};  // Return an empty vector if no solution is found (problem guarantees a solution)
    }
};
