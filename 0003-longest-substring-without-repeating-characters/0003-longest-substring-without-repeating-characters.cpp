class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        unordered_set<char>st;
        int maxLen = INT_MIN;

        if(s.size()==0)return 0;

        while(j<s.size())
        {
            while(st.find(s[j]) != st.end())
            {
                st.erase(s[i]);
                i++;
            }
            
                st.insert(s[j]);
            

            

            maxLen = max(maxLen, j-i+1);
            j++;
        }

        return maxLen;

    }
};