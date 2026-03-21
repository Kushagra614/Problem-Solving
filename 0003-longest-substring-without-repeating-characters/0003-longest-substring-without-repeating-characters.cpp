class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        int maxCount = 0;
        int i = 0;
        for(int j = 0; j < n; j++)
        {
            
            if(mp.count(s[j]))
            {
                if(mp[s[j]] >= i)
                {
                     i = mp[s[j]]+1;
                }
            }
            mp[s[j]] = j;
            int count = j-i+1;
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};