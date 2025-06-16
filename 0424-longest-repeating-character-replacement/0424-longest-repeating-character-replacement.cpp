class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int maxFreq = 0;
        int maxLen = 0;

        while (j < s.size()) {
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);

            // Check if window is valid
            while ((j - i + 1) - maxFreq > k) {
                mp[s[i]]--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};
