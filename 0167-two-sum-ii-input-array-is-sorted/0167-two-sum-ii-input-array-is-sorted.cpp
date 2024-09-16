class Solution {
public:
   vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        
        // If the sum equals the target, return the 1-based indices
        if (sum == target) {
            return {left + 1, right + 1};
        }
        // If the sum is less than the target, move the left pointer to the right
        else if (sum < target) {
            left++;
        }
        // If the sum is greater than the target, move the right pointer to the left
        else {
            right--;
        }
    }
    return {left + 1, right + 1};
   }
};