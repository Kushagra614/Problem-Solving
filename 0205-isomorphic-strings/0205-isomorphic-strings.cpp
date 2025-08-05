class Solution {
public:
    bool isIsomorphic(string s, string t) {

        //BRUTE FORCE

        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, char> mapping;
        string transformed = s;
        
        // Try to build mapping from s to t
        for (int i = 0; i < s.length(); i++) {
            char char_s = s[i];
            char char_t = t[i];
            
            if (mapping.find(char_s) != mapping.end()) {
                // Check if existing mapping conflicts
                if (mapping[char_s] != char_t) {
                    return false;
                }
            } else {
                // Check if char_t is already mapped to another character
                for (auto& pair : mapping) {
                    if (pair.second == char_t) {
                        return false;
                    }
                }
                mapping[char_s] = char_t;
            }

        }
        
       return true;

        // ------X------------X----------X------------X-----------X-----------X------------X-----------X

        // OPTIMAL APPRAOCH

        // if (s.length() != t.length()) {
        //     return false;
        // }

        // unordered_map<char, char>mp;
        // unordered_set<char>st;

        // for(int i = 0; i< s.size(); i++)
        // {
        //     char char_s = s[i];
        //     char char_t = t[i];

        //     if(mp.find(char_s) != mp.end())
        //     {
        //         if(mp[char_s] != char_t)
        //         {
        //             return false;
        //         }
        //     }
        //     else
        //     {
        //         if(st.count(char_t)) return false;
        //     }

        //     //create new mapping
        //     mp[char_s] = char_t;
        //     st.insert(char_t);
        // }

        // return true;


    }
};