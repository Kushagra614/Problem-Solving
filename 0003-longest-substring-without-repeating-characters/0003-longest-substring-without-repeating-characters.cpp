class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)return 0; 
        unordered_set<char>seen;
        int i = 0;
        int j = 0;
        int maxLen = INT_MIN;

        while(j<s.size())
        {
            //if s[j] is not in the set add it and update the len
            if(seen.find(s[j]) == seen.end())
            {
                seen.insert(s[j]);
                maxLen = max(maxLen, j - i +1);
                j++;
            }
            else
            {
                seen.erase(s[i]);
                i++;
            }
        }
        return maxLen;

    }
};