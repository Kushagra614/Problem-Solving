class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int i = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int j = 0; j < s.size(); j++) {
            mp[s[j]]++;

            maxFreq = max(maxFreq, mp[s[j]]);

            if ((j - i + 1) - maxFreq > k) {
                mp[s[i]]--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};