class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int maxFreq = 0;
        int maxLen = INT_MIN;
        unordered_map<char,int>mp;

        while(j<s.size())
        {
            mp[s[j]]++;

            //cal max freq
            maxFreq = max(maxFreq, mp[s[j]]);

            //testing val
            while((j-i+1) - maxFreq > k)
            {
                mp[s[i]]--;
                i++;

                //update max freq again
                maxFreq = max(maxFreq, mp[s[i]]);
            }
           
            maxLen = max(maxLen, j-i+1);
                j++;
        }
        return maxLen;
        
    }
};