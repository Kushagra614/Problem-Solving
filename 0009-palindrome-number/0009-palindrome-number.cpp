class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;
        
        // Single digit numbers are palindromes
        if (x < 10) return true;
        
        // Find the highest place value
        long long div = 1;
        while (x / div >= 10) {
            div *= 10;
        }
        
        while (x > 0) {
            int left = x / div;
            int right = x % 10;
            
            if (left != right) return false;
            
            // Remove the leftmost and rightmost digits
            x = (x % div) / 10;
            div /= 100;
        }
        
        return true;
    }
};