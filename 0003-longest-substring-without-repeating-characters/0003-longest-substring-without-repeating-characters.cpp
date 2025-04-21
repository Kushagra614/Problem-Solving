class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //OPTMIZED SOL
        int l = 0; int r = 0;
        int maxLen = 0;

        int hash[256];
        for (int i = 0; i < 256; i++) 
        {
            hash[i] = -1;
        }

        while(r < s.size())
        {
            if(hash[s[r]] != -1 && hash[s[r]] >= l)
            {
                {
                    l = hash[s[r]] +1;
                }
            }

            hash[s[r]] = r;
            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;





//--X------X------X---------X----------X-----------X-------X---------X----------X------X

    // BRUTE FORCE
        // int maxLen= 0;
        

        // for(int i = 0; i< s.size(); i++)
        // {
        //     string sub = "";
        //     unordered_set<char>st;
        //     for(int j = i; j< s.size(); j++)
        //     {
        //         if(st.find(s[j]) != st.end())
        //         {
        //             break;
        //         }

        //         sub += s[j];
        //         st.insert(s[j]);

        //         maxLen = max(maxLen , (int)sub.length());
        //     }


        // }
        //     return maxLen;







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