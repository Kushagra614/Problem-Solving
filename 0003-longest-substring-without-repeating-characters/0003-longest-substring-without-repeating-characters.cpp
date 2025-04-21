class Solution {
public:
    int lengthOfLongestSubstring(string s) {


        int maxLen= 0;
        

        for(int i = 0; i< s.size(); i++)
        {
            string sub = "";
            unordered_set<char>st;
            for(int j = i; j< s.size(); j++)
            {
                if(st.find(s[j]) != st.end())
                {
                    break;
                }

                sub += s[j];
                st.insert(s[j]);

                maxLen  = max(maxLen , (int)sub.length());
            }


        }
            return maxLen;







        // int maxLen = 0;
        

        // for(int i = 0; i< s.size() ; i++)
        // {
        //     string sub = "";
        //     unordered_map<char, bool>mp;
        //     for(int j = i; j<s.size(); j++)
        //     {
        //         if(mp[s[j]] == true)
        //         {
        //             break;
        //         }

        //         mp[s[j]] = true;
        //         sub += s[j];
        //         maxLen = max(maxLen, (int)sub.length());
        //     }
        // }
        //     return maxLen;
        
      
    }
};