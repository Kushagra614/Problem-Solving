class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;  // Start of the window
        int j = 0;  // End of the window
        int maxLen = 0;
        unordered_map<char, int> map;
        
        while (j < n) {
            if (map.find(s[j]) == map.end() || map[s[j]] < i) {
                // If not found or the last occurrence is outside the current window
                map[s[j]] = j;  // Insert or update the character position
                maxLen = max(maxLen, j - i + 1);  // Update max length
                j++;
            } else {
                // If found within the current window, move i
                i = map[s[j]] + 1;  // Move i to the next position after the last occurrence of s[j]
            }
        }

        return maxLen;
    }
};
